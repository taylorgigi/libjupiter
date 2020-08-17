#include "Mutex.h"
#include "Condition.h"
#include "CountDownLatch.h"

namespace jupiter
{

CountDownLatch::CountDownLatch(int count)
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
    while(count_ > 0)
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

} // namespace jupiter
