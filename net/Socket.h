//
// Created by taylor on 2020/8/25.
//

#ifndef JUPITER_SOCKET_H
#define JUPITER_SOCKET_H

#include <boost/noncopyable.hpp>

class Socket: public boost::noncopyable
{
public:
    explicit Socket(int fd);
    ~Socket();
    int fd() const;
    void shutdown_write();
private:
    const int fd_;
};


#endif //JUPITER_SOCKET_H
