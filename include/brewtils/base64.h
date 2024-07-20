#pragma once

#include <cstring>
#include <stdexcept>
#include <string>

namespace brewtils {

namespace base64 {

std::string encode(const std::string &data) noexcept(true);

std::string decode(const std::string &data) noexcept(false);

bool isValid(const std::string &data) noexcept(true);

} // namespace base64

} // namespace brewtils