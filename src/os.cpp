#include <brewtils/os.h>

std::string brewtils::os::joinPath(const std::string &path1,
                                   const std::string &path2) noexcept(true) {
  return std::filesystem::path(path1).append(path2).string();
}
