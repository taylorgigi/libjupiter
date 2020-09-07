//
// Created by taylor on 2020/8/25.
//

#ifndef JUPITER_SOCKET_H
#define JUPITER_SOCKET_H

#include <boost/noncopyable.hpp>
#include "INetAddress.h"

class Socket: public boost::noncopyable
{
public:
    explicit Socket(int fd);
    ~Socket();
    int fd() const;
    void bind_address(const INetAddress& addr);
    void listen();
    int accept();
    void shutdown_write();
    void set_tcp_nodelay(bool on);
    void set_reuse_addr(bool on);
    void set_reuse_port(bool on);
    void set_keep_alive(bool on);
private:
    const int fd_;
};


#endif //JUPITER_SOCKET_H
