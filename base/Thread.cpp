#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/sysinfo.h>
#include "Thread.h"


struct ThreadArg
{
	typedef jupiter::Thread::ThreadFunc ThreadFunc;

	ThreadFunc 		func;
	std::string 		name;
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
		num_created_++;
	}

	void Thread::join()
	{
		if(launched) {
			pthread_join(ptid, NULL);
			launched = false;
			num_created_--;
		}
	}

	void Thread::set_affinity(uint32_t cpu_mask)
	{
		if(launched) {
			cpu_set_t cpuset;
			CPU_ZERO(&cpuset);
			for(int i=0; i<32; ++i) {
				if((uint32_t)1 << i)
					CPU_SET(i, &cpuset);
			}
			int ret = pthread_setaffinity_np(ptid, sizeof(cpuset), &cpuset);
			if(ret)
				;// to-do-list: error log
		}
	}
} // namespace jupiter

