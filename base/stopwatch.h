// this utility is used to measure that how long a function or a task spends.



#ifndef LIBJUPITER_STOPWATCH_INCLUDE_H
#define LIBJUPITER_STOPWATCH_INCLUDE_H

#include <cstdint>
#include <chrono>


namespace jupiter { // namespace jupiter




class stopwatch
{
public:
    stopwatch(): start_time(std::chrono::steady_clock::time_point::min()) {}
    ~stopwatch()
    {
        start_time = std::chrono::steady_clock::time_point::min();
    }

    //@return start timing
    void start()
    {
        start_time = std::chrono::steady_clock::now();
    }

    //@return true if stopwatch has been started, otherwith false
    bool is_started()
    {
        return(start_time == std::chrono::steady_clock::time_point::min());
    }

    //@return elapsed time(milliseconds) relative to start time
    uint64_t stop()
    {
        if(start_time != std::chrono::steady_clock::time_point::min()) {
	    std::chrono::steady_clock::time_point now_time = std::chrono::steady_clock::now();
	    std::chrono::milliseconds t = std::chrono::duration_cast<std::chrono::milliseconds>(now_time - start_time);
	    start_time = std::chrono::steady_clock::time_point::min();
	    return t.count();
	}
	return 0;
    }
private:
    std::chrono::steady_clock::time_point start_time;
};





} // namespace jupiter


#endif

