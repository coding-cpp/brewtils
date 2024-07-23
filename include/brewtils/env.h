#pragma once

#include <brewtils/os.h>
#include <brewtils/string.h>

namespace brewtils {

namespace env {

void init(std::string path = brewtils::os::dir::current()) noexcept(true);

std::string get(const std::string &key) noexcept(true);

void set(const std::string &key, const std::string &value) noexcept(true);

} // namespace env

} // namespace brewtils