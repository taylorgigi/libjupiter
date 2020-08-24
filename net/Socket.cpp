//
// Created by taylor on 2020/8/25.
//

#include <sys/socket.h>
#include "Socket.h"

Socket::Socket(int fd)
: fd_(fd)
{}

Socket::~Socket()
{
    ::close(fd_);
}

int Socket::fd() const
{
    return fd_;
}

void Socket::shutdown_write()
{
    ::shutdown(fd_, SHUT_WR);
}
