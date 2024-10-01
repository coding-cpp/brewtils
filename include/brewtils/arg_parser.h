#pragma once

#include <brewtils/env.h>

namespace brewtils {

class ArgParser {
private:
  std::string prefix;

public:
  ArgParser(const std::string &prefix = "BREWTILS_") noexcept(true);
  ~ArgParser() noexcept(true);

  void parse(int argc, char **argv) noexcept(true);
};

} // namespace brewtils
