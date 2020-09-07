//
// Created by taylor on 2020/9/7.
//

#include <arpa/inet.h>
#include <cstring>
#include "INetAddress.h"

namespace jupiter
{

INetAddress::INetAddress(uint16_t port, bool loopback_only, bool ipv6)
{
   if(ipv6) {
       memset(&addr6_, 0, sizeof addr6_);
       addr6_.sin6_family = AF_INET6;
       addr6_.sin6_port = htons(port);
       addr6_.sin6_addr = loopback_only ? in6addr_loopback : in6addr_any;
   }
   else {
       memset(&addr_, 0, sizeof addr_);
       addr_.sin_family = AF_INET;
       addr_.sin_port = htons(port);
       addr_.sin_addr = loopback_only ? INADDR_LOOPBACK : INADDR_ANY;
   }
}

INetAddress::INetAddress(const char *ip, uint16_t port, bool ipv6)
{
    if(ipv6) {
        memset(&addr6_, 0, sizeof addr6_);
        addr6_.sin6_family = AF_INET6;
        addr6_.sin6_port = htons(port);
        if(inet_pton(AF_INET6, ip, &addr6_.sin6_addr) <= 0) {
            //to do: error log
        }
    }
    else {
        memset(&addr_, 0, sizeof addr_);
        addr_.sin_family = AF_INET;
        addr_.sin_port = htons(port);
        if(inet_pton(AF_INET, ip, &addr_.sin_addr) <= 0) {
            //to do: error log
        }
    }
}

INetAddress::~INetAddress()
{}

uint16_t INetAddress::to_port()
{
    const struct sockaddr* addr = get_sockaddr();
    if(addr->sa_family == AF_INET)
        return ntohs(addr_.sin_port);
    return ntohs(addr6_.sin6_port);
}

std::string INetAddress::to_ip()
{
    const struct sockaddr* addr = get_sockaddr();
    std::string buf(INET6_ADDRSTRLEN, 0);
    if(addr->sa_family == AF_INET) {
        inet_ntop(AF_INET, &addr_.sin_addr, const_cast<char*>(buf.c_str()), INET6_ADDRSTRLEN);
    }
    else {
        inet_ntop(AF_INET6, &addr_.sin6_addr, const_cast<char*>(buf.c_str()), INET6_ADDRSTRLEN);
    }
    return std::move(buf);
}

std::string INetAddress::to_ip_port()
{
    char port[8] = {0};
    sprintf(port, "%u", to_port());
    std::string buf = std::move(to_ip());
    buf.append(":");
    buf.append(port);
    return std::move(buf);
}

uint32_t INetAddress::ip_net_order()
{
    if(family() == AF_INET)
        return addr_.sin_addr.s_addr;
    return 0;
}

uint16_t INetAddress::port_net_order()
{
    if(family() == AF_INET)
        return addr_.sin_port;
    return addr6_.sin6_port;
}

const struct sockaddr* INetAddress::get_sockaddr()
{
    return static_cast<struct socket_addr*>(&addr6_);
}

}
