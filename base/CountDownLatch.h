//
// Created by taylor on 2020/8/17.
//

#ifndef JUPITER_COUNTDOWNLATCH_H
#define JUPITER_COUNTDOWNLATCH_H

class Mutex;
class Condition;

class CountDownLatch {
public:
    explicit CountDownLatch(int count);
    ~CountDownLatch();
    void wait();
    void count_down();
    int get_count();
private:
    Mutex mutex;
    Condition cond;
    int count_;
};


#endif //JUPITER_COUNTDOWNLATCH_H
