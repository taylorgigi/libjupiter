//
// Created by taylor on 2020/8/17.
//

#include "Mutex.h"
#include "Condition.h"
#include "Thread.h"
#include "ThreadPool.h"

namespace jupiter {

ThreadPool::ThreadPool(const std::string &name)
: name_(name),
  running_(false),
  not_empty_(mutex_),
  not_full_(mutex_)
{
}

ThreadPool::~ThreadPool() {
}

void ThreadPool::set_max_tasks(int v)
{
    max_tasks_ = v;
}

int ThreadPool::num_of_tasks() const
{
    MutexGuard guard(mutex_);
    return queue_.size();
}

void ThreadPool::start(int num_threads)
{
    running_ = true;
    threads_.reserve(num_threads);
    for(auto i=0; i<num_threads; ++i) {
        char buf[64] = {0};
        sprintf(buf, "%s-%d", name_.c_str(), i);
        threads_.emplace_back(std::make_unique<Thread>(std::bind(&ThreadPool::run_in_thread, this), buf));
        threads_[i]->launch();
    }
}

void ThreadPool::stop()
{
    {
        MutexGuard guard(mutex_);
        running_ = false;
        not_empty_.notify_all();
    }
    for(auto& t : threads_) {
        t->join();
    }
}

void ThreadPool::run(Task task)
{
    MutexGuard guard(mutex_);
    while(is_full()) {
        not_full_.wait();
    }
    queue_.push_back(std::move(task));
    not_empty_.notify();
}

ThreadPool::Task ThreadPool::take()
{
    MutexGuard guard(mutex_);
    while(queue_.empty()) {
        not_empty_.wait();
    }
    Task task;
    if(!queue_.empty()) {
        task = queue_.front();
        queue_.pop_front();
        if(max_tasks_ > 0)
            not_full_.notify();
    }
    return task;
}

void ThreadPool::run_in_thread()
{
    while(running_.load()) {
        Task task(take());
        if(task)
            task();
    }
}

} // namespace jupiter
