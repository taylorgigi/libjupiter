#ifndef JUPITER_LIB_THREAD_INCLUDE_H
#define JUPITER_LIB_THREAD_INCLUDE_H

#include <string>
#include <memory>
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
	private:
		bool					launched;
		ThreadFunc 				func;
		std::shared_ptr<pid_t>	tid;
		pthread_t				ptid;
		std::string 			name;
};

} // namespace jupiter

#endif

