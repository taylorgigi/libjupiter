#ifndef JUPITER_MUTEX_INCLUDE_H
#define JUPITER_MUTEX_INCLUDE_H

#include <pthread.h>
#include <boost/noncopyable.hpp>

namespace jupiter
{

class Mutex: public boost::noncopyable
{
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();
		pthread_mutex_t* get_pthread_mutex();
	private:
		pthread_mutex_t mutex;
};

class MutexGuard: public boost::noncopyable
{
	public:
		explicit MutexGuard(Mutex& mutex_);
		~MutexGuard();
	private:
		Mutex& mutex;
};

} // namespace jupiter

#endif

