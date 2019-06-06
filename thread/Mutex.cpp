#include "Mutex.h"

namespace jupiter
{

Mutex::Mutex()
{
	pthread_mutex_init(&mutex, NULL);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&mutex);
}

void Mutex::lock()
{
	pthread_mutex_lock(&mutex);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&mutex);
}

pthread_mutex_t* Mutex::get_pthread_mutex()
{
	return &mutex;
}

MutexGuard::MutexGuard(Mutex& mutex_): mutex(mutex_)
{
	mutex.lock();
}

MutexGuard::~MutexGuard()
{
	mutex.unlock();
}

} // jupiter
