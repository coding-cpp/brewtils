#include <brewtils/os/file.h>

bool brewtils::os::file::exists(const std::string &path) noexcept(true) {
  return std::filesystem::exists(path) &&
         std::filesystem::is_regular_file(path);
}

void brewtils::os::file::create(const std::string &path) noexcept(false) {
  if (brewtils::os::file::exists(path)) {
    throw std::runtime_error("File already exists: " + path);
  }

  std::ofstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to create file: " + path);
  }

  file.close();
}

std::string brewtils::os::file::read(const std::string &path) noexcept(false) {
  if (!brewtils::os::file::exists(path)) {
    throw std::runtime_error("File does not exist: " + path);
  }

  std::ifstream file(path);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + path);
  }

  std::string content;
  std::string line;
  while (std::getline(file, line)) {
    content += line + "\n";
  }

  file.close();
  return content;
}

void brewtils::os::file::remove(const std::string &path) noexcept(false) {
  if (!brewtils::os::file::exists(path)) {
    throw std::runtime_error("File does not exist: " + path);
  }

  if (!std::filesystem::remove(path)) {
    throw std::runtime_error("Failed to remove file: " + path);
  }
}