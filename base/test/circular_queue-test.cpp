//
// Created by taylor on 2020/8/22.
//

#include <iostream>
#include "../CircularQueue.h"

int main(int argc, char *argv[])
{
    jupiter::CircularQueue<int> circular_que(5);
    if(circular_que.empty())
        std::cout << "empty" << std::endl;
    circular_que.enqueue(1);
    circular_que.enqueue(2);
    circular_que.enqueue(3);
    circular_que.enqueue(4);
    std::cout << "queue size: " << circular_que.size() << std::endl;
    if(circular_que.full())
        std::cout << "full" << std::endl;
    circular_que.enqueue(5);
    circular_que.enqueue(6);
    std::cout << "queue size: " << circular_que.size() << std::endl;

    return 0;
}
