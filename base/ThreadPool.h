//
// Created by taylor on 2020/8/17.
//

#ifndef JUPITER_THREADPOOL_H
#define JUPITER_THREADPOOL_H

#include <atomic>
#include <deque>
#include <functional>
#include <memory>
#include <string>
#include <boost/noncopyable.hpp>

namespace jupiter {

class Mutex;
class Condition;
class Thread;

class ThreadPool : public boost::noncopyable {
public:
    typedef std::function<void()> Task;

    ThreadPool(const std::string& name = "ThreadPool");
    ~ThreadPool();
    void set_max_tasks(size_t v);
    size_t num_of_tasks() const;
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
    mutable Mutex mutex_;
    size_t max_tasks_;
    Condition not_empty_;
    Condition not_full_;
    std::deque<Task> queue_;
    std::vector<std::unique_ptr<Thread>> threads_;
};

} // namespace jupiter

#endif //JUPITER_THREADPOOL_H
