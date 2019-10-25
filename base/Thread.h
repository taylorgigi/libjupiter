#ifndef LIBJJUPITER_LIB_THREAD_INCLUDE_H
#define LIBJJUPITER_LIB_THREAD_INCLUDE_H

#include <string>
#include <memory>
#include <atomic>
#include <boost/noncopyable.hpp>
#include <functional>
#include <pthread.h>

namespace jupiter
{

class Thread: public boost::noncopyable
{
	public:
		typedef std::function<void()> ThreadFunc;
		explicit Thread(ThreadFunc func_, const char *name_="");
		~Thread();
		void launch();
		void join();
		// this func should be called after launch() has been called
		void set_affinity(int cpu);

		static uint32_t num_created() { return num_created_.load(); }
	private:
		static std::atomic<uint32_t>		num_created_ {0};
		bool					launched;
		ThreadFunc 				func;
		std::shared_ptr<pid_t>			tid;
		pthread_t				ptid;
		std::string				name;
};

} // namespace jupiter

#endif

