//
// Created by taylor on 2020/9/6.
//

#ifndef JUPITER_RING_H
#define JUPITER_RING_H

#include <boost/noncopyable.hpp>

namespace jupiter
{

constexpr const int CACHE_LINE_SIZE = 64;

struct RingHeadTail
{
    volatile uint32_t head;
    volatile uint32_t tail;
    bool single;
};

template<typename T>
class Ring: public boost::noncopyable
{
public:
    Ring(const char *name, unsigned int count, unsigned int flags)
    : name_(name),
    flags_(flags)
    {
    }
    ~Ring();
private:
    bool is_sp_;
    uint32_t flags_;
    uint32_t size_;
    uint32_t capacity_;
    std::string name_;
    RingHeadTail alignas(CACHE_LINE_SIZE) proc;
    RingHeadTail alignas(CACHE_LINE_SIZE) cons;
    std::unique_ptr<T[]> buffer;
};

} // namespace jupiter



#endif //JUPITER_RING_H
