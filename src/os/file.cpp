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

  try {
    while (std::getline(file, line)) {
      content += line + "\n";
    }
  } catch (const std::exception &e) {
    logger::error("Failed to read file: " + path + " - " +
                      std::string(e.what()),
                  "std::string brewtils::os::file::read(const "
                  "std::string &path) noexcept(false)");
  } catch (...) {
    logger::error("Failed to read file: " + path,
                  "std::string brewtils::os::file::read(const "
                  "std::string &path) noexcept(false)");
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

uint32_t brewtils::os::file::size(const std::string &path) noexcept(false) {
  if (!brewtils::os::file::exists(path)) {
    logger::error("File does not exist: " + path,
                  "uint32_t brewtils::os::file::size(const std::string &path) "
                  "noexcept(false)");
  }

  return std::filesystem::file_size(path);
}
