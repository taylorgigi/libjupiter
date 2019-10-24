#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "Thread.h"


struct ThreadArg
{
	typedef jupiter::Thread::ThreadFunc ThreadFunc;

	ThreadFunc 				func;
	std::string 			name;
	std::weak_ptr<pid_t> 	tid;

	ThreadArg(ThreadFunc func_, std::string& name_, std::shared_ptr<pid_t>& tid_): func(func_), name(name_), tid(tid_)
	{
	}

	void run()
	{
		std::shared_ptr<pid_t> stid = tid.lock();
		if(stid) {
			*stid = static_cast<pid_t>(::syscall(SYS_gettid));
		}
		func();
	}
};

void *launch(void *arg_)
{
	ThreadArg *arg = static_cast<ThreadArg*>(arg_);
	arg->run();
	delete arg;
	return NULL;
}

namespace jupiter
{

	Thread::Thread(ThreadFunc func_, const char *name_): launched(false), func(func_), name(name_)
	{
		tid = std::make_shared<pid_t>(0);
	}

	Thread::~Thread()
	{
	}

	void Thread::launch()
	{
		launched = true;
		ThreadArg *arg = new ThreadArg(func, name, tid);
		if(pthread_create(&ptid, NULL, ::launch, arg)) {
			launched = false;
			delete arg;
			abort();
		}
	}

	void Thread::join()
	{
		if(launched) {
			pthread_join(ptid, NULL);
			launched = false;
		}
	}

	void Thread::set_affinity(int cpu)
	{
		if(launched) {
			cpu_set_t cpuset;
			CPU_ZERO(&cpuset);
			CPU_SET(cpu, &cpuset);
			pthread_setaffinity_np(ptid, sizeof(cpuset), &cpuset);
		}
	}
} // namespace jupiter

