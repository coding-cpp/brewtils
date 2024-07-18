#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace brewtils {

namespace os {

namespace dir {

void create(const std::string &path) noexcept(false);

std::string current() noexcept(true);

std::vector<std::string> list(const std::string &path) noexcept(true);

void remove(const std::string &path) noexcept(false);

} // namespace dir

} // namespace os

} // namespace brewtils