//
// Created by taylor on 2020/8/17.
//

#include "../Mutex.h"
#include "../Condition.h"
#include "../CountDownLatch.h"
#include "../Thread.h"
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char *argv[])
{
    const int kThreadNum = 3;
    jupiter::CountDownLatch latch(kThreadNum);
    std::cout << "count latch: " << latch.get_count() << std::endl;
    std::vector<std::unique_ptr<jupiter::Thread>> threads;
    for(auto i=0; i<kThreadNum; ++i) {
        char buf[16] = {0};
        sprintf(buf, "thread-%2d", i);
        threads.push_back(std::make_unique<jupiter::Thread>(std::bind(&jupiter::CountDownLatch::count_down, &latch), buf));
        threads[i]->launch();
    }
    std::cout << "count latch waiting ..." << std::endl;
    latch.wait();
    std::cout << "count latch: " << latch.get_count() << std::endl;
    std::cout << "joint threads" << std::endl;
    for(auto& v : threads) {
        v->join();
    }
    std::cout << "will exit" << std::endl;

    return 0;
}
