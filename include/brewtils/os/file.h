#pragma once

#include <filesystem>
#include <fstream>
#include <string>

namespace brewtils {

namespace os {

namespace file {

bool exists(const std::string &path) noexcept(true);

void create(const std::string &path) noexcept(false);

std::string read(const std::string &path) noexcept(false);

void remove(const std::string &path) noexcept(false);

} // namespace file

} // namespace os

} // namespace brewtils