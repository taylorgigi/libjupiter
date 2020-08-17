//
// Created by taylor on 2020/8/17.
//

#include <cstdio>
#include "../Mutex.h"
#include "../Condition.h"
#include "../Thread.h"
#include "../ThreadPool.h"
#include "../CountDownLatch.h"

void print(void *arg)
{
    long id = (long)(arg);
    printf( "task-%ld\n", id);
}

int main(int argc, char *argv[])
{
    jupiter::ThreadPool thread_pool("ThreadPool");
    thread_pool.set_max_tasks(100);
    thread_pool.start(10);
    const int kTaskNum = 1000;
    printf("launch thread ...\n");
    for(long i=0; i<kTaskNum; ++i) {
        thread_pool.run(std::bind(&print, (void*)i));
    }
    jupiter::CountDownLatch latch(1);
    thread_pool.run(std::bind(&jupiter::CountDownLatch::count_down, &latch));
    printf("latch waiting ...\n");
    latch.wait();
    printf("thread pool stopping ...\n");
    thread_pool.stop();
    printf("thread pool still have %lu tasks\n", thread_pool.num_of_tasks());
    printf("program exit\n");

    return 0;
}
