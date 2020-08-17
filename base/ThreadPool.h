//
// Created by taylor on 2020/8/17.
//

#ifndef JUPITER_THREADPOOL_H
#define JUPITER_THREADPOOL_H

#include <atomic>
#include <deque>
#include <functional>
#include <string>
#include <boost/noncopyable.hpp>

namespace jupiter {

class Mutex;
class Condition;
class Thread;

class ThreadPool : public boost::noncopyable {
public:
    typedef std::function<void(void)> Task;

    ThreadPool(const std::string& name = "ThreadPool");
    ~ThreadPool();
    void max_tasks(int v);
    int max_tasks() const;
    void start(int num_threads);
    void stop();
    void run(Task task);
private:
    void run_in_thread();
    bool is_full() { return(max_tasks_>0 && queue_.size() == max_tasks_); }
    Task take();
private:
    std::atomic<bool> running_;
    std::string name_;
    Mutex mutex_;
    int max_tasks_;
    Condition not_empty_;
    Condition not_full_;
    std::deque<Task> queue_;
    std::vector<std::unique_ptr<Thread>> threads_;
};

} // namespace jupiter

#endif //JUPITER_THREADPOOL_H
