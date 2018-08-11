#include "Condition.h"

namespace jupiter
{
	Condition::Condition(Mutex& mutex_): mutex(mutex_)
	{
		pthread_cond_init(&cond, NULL);
	}

	Condition::~Condition()
	{
		pthread_cond_destroy(&cond);
	}

	void Condition::wait()
	{
		pthread_cond_wait(&cond, mutex.get_pthread_mutex());
	}

	void Condition::timed_wait(uint64_t nsec)
	{
			struct timespec tv;
			tv.tv_sec = nsec/1000000000;
			tv.tv_nsec = nsec%1000000000;
			pthread_cond_timedwait(&cond, mutex.get_pthread_mutex(), &tv);
	}

	void Condition::notify()
	{
		pthread_cond_signal(&cond);
	}

	void Condition::notify_all()
	{
		pthread_cond_broadcast(&cond);
	}
}

