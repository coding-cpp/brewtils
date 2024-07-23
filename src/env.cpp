#include <brewtils/env.h>

void brewtils::env::init(std::string path) noexcept(true) {
  if (brewtils::os::dir::exists(path)) {
    path = brewtils::os::joinPath(path, ".env");
  }

  if (!brewtils::os::file::exists(path)) {
    logger::warning("No .env file found at " + path);
    return;
  }

  const std::string data = brewtils::os::file::read(path);
  for (const std::string &line : brewtils::string::split(data, "\n")) {
    const std::vector<std::string> parts = brewtils::string::split(line, "=");
    if (parts.size() == 1 && parts[0].empty()) {
      continue;
    }

    if (parts.size() != 2) {
      logger::warning("Invalid .env line: " + line);
      continue;
    }

    brewtils::env::set(parts[0], parts[1]);
  }
}

std::string brewtils::env::get(const std::string &key) noexcept(true) {
  return std::getenv(key.c_str());
}

void brewtils::env::set(const std::string &key,
                        const std::string &value) noexcept(true) {
  if (value.empty()) {
    logger::warning("Unsetting environment variable " + key);
    unsetenv(key.c_str());
  } else {
    setenv(key.c_str(), value.c_str(), 1);
  }

  return;
}