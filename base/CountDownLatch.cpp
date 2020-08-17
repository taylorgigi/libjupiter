#include "CountDownLatch.h"
#include "Mutex.h"

CountDownLatch::CountDownLatch(uint32_t count)
: cond(mutex),
count_(count)
{
}

CountDownLatch::~CountDownLatch()
{
}

void CountDownLatch::wait()
{
    MutexGuard guard(mutex);
    if(count_ > 0)
        cond.wait();
}

void CountDownLatch::count_down()
{
    MutexGuard guard(mutex);
    --count_;
    if(count_ == 0)
        cond.notify_all();
}

int CountDownLatch::get_count()
{
    MutexGuard guard(mutex);
    return count_;
}
