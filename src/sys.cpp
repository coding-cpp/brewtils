#include <brewtils/sys.h>

size_t brewtils::sys::send(int sockfd, const void *buf, size_t len, int flags) {
  return ::send(sockfd, buf, len, flags);
}

size_t brewtils::sys::recv(int sockfd, void *buf, size_t len, int flags) {
  return ::recv(sockfd, buf, len, flags);
}

int brewtils::sys::socket(int domain, int type, int protocol) noexcept(true) {
  return ::socket(domain, type, protocol);
}

int brewtils::sys::listen(int sockfd, int backlog) noexcept(true) {
  return ::listen(sockfd, backlog);
}

int brewtils::sys::bind(int sockfd, const struct sockaddr *addr,
                        socklen_t addrlen) noexcept(true) {
  return ::bind(sockfd, addr, addrlen);
}