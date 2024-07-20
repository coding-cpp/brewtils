#include <brewtils/os/file.h>

bool brewtils::os::file::exists(const std::string &path) noexcept(true) {
  return std::filesystem::exists(path) &&
         std::filesystem::is_regular_file(path);
}

void brewtils::os::file::create(const std::string &path) noexcept(false) {
  if (brewtils::os::file::exists(path)) {
    logger::error("File already exists: " + path,
                  "void brewtils::os::file::create(const std::string &path) "
                  "noexcept(false)");
  }

  std::ofstream file(path);
  if (!file.is_open()) {
    logger::error("Failed to create file: " + path,
                  "void brewtils::os::file::create(const std::string &path) "
                  "noexcept(false)");
  }

  file.close();
}

std::string brewtils::os::file::read(const std::string &path) noexcept(false) {
  if (!brewtils::os::file::exists(path)) {
    logger::error("File does not exist: " + path,
                  "std::string brewtils::os::file::read(const std::string "
                  "&path) noexcept(false)");
  }

  std::ifstream file(path);
  if (!file.is_open()) {
    logger::error("Failed to open file: " + path,
                  "std::string brewtils::os::file::read(const "
                  "std::string &path) noexcept(false)");
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
    logger::error("File does not exist: " + path,
                  "void brewtils::os::file::remove(const std::string &path) "
                  "noexcept(false)");
  }

  if (!std::filesystem::remove(path)) {
    logger::error("Failed to remove file: " + path,
                  "void brewtils::os::file::remove(const std::string &path) "
                  "noexcept(false)");
  }

  logger::warning("File removed: " + path,
                  "void brewtils::os::file::remove(const std::string &path) "
                  "noexcept(false)");
}