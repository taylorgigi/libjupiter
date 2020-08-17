#include <iostream>
#include <unistd.h>
#include "../Stopwatch.h"

using namespace jupiter;

int main()
{
    Stopwatch watch1;
    watch1.start();
    sleep(1);
    uint64_t t = watch1.stop();
    std::cout << "cost: " << t << " nanoseconds" << std::endl;

    return 0;
}

