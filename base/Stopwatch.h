// this utility is used to measure that how long a function or a task spends.



#ifndef LIBJUPITER_STOPWATCH_INCLUDE_H
#define LIBJUPITER_STOPWATCH_INCLUDE_H

#include <cstdint>
#include <chrono>


namespace jupiter { // namespace jupiter




class Stopwatch
{
public:
    Stopwatch(): start_time(std::chrono::steady_clock::time_point::min()) {}
    ~Stopwatch()
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

    //@return elapsed time(nanoseconds) relative to start time
    uint64_t stop()
    {
        if(start_time != std::chrono::steady_clock::time_point::min()) {
	    std::chrono::steady_clock::time_point now_time = std::chrono::steady_clock::now();
	    std::chrono::nanoseconds t = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - start_time);
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

