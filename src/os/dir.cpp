#include <brewtils/os/dir.h>

void brewtils::os::dir::create(const std::string &path) noexcept(false) {
  std::filesystem::create_directory(path);
}

std::string brewtils::os::dir::current() noexcept(true) {
  return std::filesystem::current_path().string();
}

std::vector<std::string>
brewtils::os::dir::list(const std::string &path) noexcept(true) {
  std::vector<std::string> files;
  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    files.push_back(entry.path().string());
  }
  return files;
}

void brewtils::os::dir::remove(const std::string &path) noexcept(false) {
  std::filesystem::remove_all(path);
}