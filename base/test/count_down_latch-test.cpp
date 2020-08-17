//
// Created by taylor on 2020/8/17.
//

#include "Mutex.h"
#include "Condition.h"
#include "CountDownLatch.h"
#include <memory>
#include <vector>

int main(int argc char *argv[])
{
    const int kThtreadNum = 3;
    CountDownLatch latch(kThtreadNum);
    std::vector<std::unique_ptr<Thread>> theads;
    for(auto i=0; i<kThtreadNum; ++i) {
        char buf[16] = {0};
        sprintf(buf, "thread-%2d", i);
        threads.push_back(std::make_unique<Thread>(std::bind(CountDownLatch::count_down, &latch), buf));
    }
    std::cout << "count latch waiting ..." << std::endl;
    latch.wait();
    for(auto v : threads) {
        v->join();
    }
    std::cout << "will exit" << std::endl;

    return 0;
}
