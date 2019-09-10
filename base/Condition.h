#ifndef LIBJUPITER_CONDITION_INCLUDE_H
#define LIBJUPITER_CONDITION_INCLUDE_H

#include <cstdint>
#include <pthread.h>
#include <boost/noncopyable.hpp>

namespace jupiter
{

class Mutex;

class Condition: public boost::noncopyable
{
	public:
		explicit Condition(Mutex& mutex_);
		~Condition();
		void wait();
		void timed_wait(uint64_t nsec);
		void notify();
		void notify_all();
	private:
		Mutex& mutex;
		pthread_cond_t cond;
};

} // namespace jupiter

#endif

