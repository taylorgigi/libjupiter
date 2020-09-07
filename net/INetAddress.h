//
// Created by taylor on 2020/9/7.
//

#ifndef JUPITER_INETADDRESS_H
#define JUPITER_INETADDRESS_H

#include <boost/noncopyable.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

namespace jupiter
{

class INetAddress: boost::noncopyable
{
public:
    INetAddress(uint16_t port = 0, bool loopback_only = false, bool ipv6 = false);
    INetAddress(const char* ip, uint16_t port, bool ipv6 = false);
    ~INetAddress();
    sa_family_t family() { return addr_.sin_family; }
    uint16_t to_port();
    std::string to_ip();
    std::string to_ip_port();
    uint32_t ip_net_order();
    uint16_t port_net_order();
private:
    const struct sockaddr* get_sockaddr();
private:
    union {
        struct sockaddr_in addr_;
        struct sockaddr_in6 addr6_;
    };
};

} // namespace jupiter



#endif //JUPITER_INETADDRESS_H
