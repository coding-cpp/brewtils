#include <brewtils/env.h>

void brewtils::env::init(std::string path) noexcept(false) {
  if (brewtils::os::dir::exists(path)) {
    path = brewtils::os::joinPath(path, ".env");
  }

  if (!brewtils::os::file::exists(path)) {
    logger::error("No .env file found at " + path);
    return;
  }

  const std::string data = brewtils::os::file::read(path);
  std::string key, value;
  for (const std::string &line : brewtils::string::split(data, "\n")) {
    std::size_t pos = line.rfind('=');
    if (pos == std::string::npos) {
      continue;
    }

    key = line.substr(0, pos);
    value = line.substr(pos + 1);
    brewtils::env::set(key, value);
  }

  return;
}

std::string brewtils::env::get(const std::string &key) noexcept(true) {
  return std::getenv(key.c_str());
}

void brewtils::env::set(const std::string &key,
                        const std::string &value) noexcept(false) {
  if (value.empty()) {
    logger::warning("Unsetting environment variable " + key);
    if (unsetenv(key.c_str()) != 0) {
      logger::error("Failed to unset environment variable " + key,
                    "void set(const std::string &key, const std::string "
                    "&value) noexcept(false)");
    }
  } else {
    if (setenv(key.c_str(), value.c_str(), 1) != 0) {
      logger::error("Failed to set environment variable " + key,
                    "void set(const std::string &key, const std::string "
                    "&value) noexcept(false)");
    }
  }

  return;
}
