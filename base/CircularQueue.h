//
// Created by taylor on 2020/8/22.
//

#ifndef JUPITER_CIRCULARQUEUE_H
#define JUPITER_CIRCULARQUEUE_H

#include <memory>
#include "Mutex.h"

namespace jupiter {


template<typename T>
class CircularQueue {
public:
    explicit CircularQueue(size_t capacity)
            : rp_(0),
              wp_(0),
              capacity_(capacity),
              size_(0),
              buffer_(std::make_unique<T[]>(capacity_)) {}

    ~CircularQueue() {}

    template <typename U>
    void enqueue(U&& v) {
        MutexGuard guard(mutex_);
        buffer_[wp_] = v;
        if (full_())
            rp_ = (rp_ + 1) % capacity_;
        else
            ++size_;
        wp_ = (wp_ + 1) % capacity_;
    }

    bool dequeue(T &v) {
        MutexGuard guard(mutex_);
        if (empty_())
            return false;
        v = buffer_[rp_];
        rp_ = (rp_ + 1) % capacity_;
        --size_;
        return true;
    }

    bool empty() {
        MutexGuard guard(mutex_);
        return empty_();
    }

    bool full() {
        MutexGuard guard(mutex_);
        return full_();
    }

    size_t size() {
        MutexGuard guard(mutex_);
        return size_;
    }

    size_t capacity() {
        return capacity_;
    }

private:
    bool full_() {
        return ((wp_ + 1) % capacity_ == rp_);
    }

    bool empty_() {
        return (rp_ == wp_);
    }

private:
    size_t rp_;
    size_t wp_;
    size_t capacity_;
    size_t size_;
    Mutex mutex_;
    std::unique_ptr<T[]> buffer_;
};

} // namespace jupiter

#endif //JUPITER_CIRCULARQUEUE_H
