#include <iostream>
#include <unistd.h>
#include "stopwatch.h"

using namespace jupiter;

int main()
{
    stopwatch watch1;
    watch1.start();
    sleep(1);
    uint64_t t = watch1.stop();
    std::cout << "cost: " << t << " milliseconds" << std::endl;

    return 0;
}

