///////////////////////////////////////////////////////////
//  Channel.h
//  Implementation of the Class Channel
//  Created on:      26-七月-2019 17:47:05
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_DD6A6F05_C975_4f16_8268_198920A973BA__INCLUDED_)
#define EA_DD6A6F05_C975_4f16_8268_198920A973BA__INCLUDED_

#include <cstdint>
#include <functional>

class EventLoop;

class Channel
{
public:
	typedef std::function<void(void)> EventCallBack;


	Channel(int fd__ = -1, EventLoop* event_loop__ = nullptr);
	~Channel();
	int fd();
	void index(int index__);
	int index();
	uint32_t events();
	void set_read_callback(Channel::EventCallBack callback);
	void set_write_callback(Channel::EventCallBack callback);
	void set_close_callback(Channel::EventCallBack callback);
	void set_error_callback(Channel::EventCallBack callback);
	void handle_event();
	void remove();
	void enable_read();
	void disable_read();
	void enable_write();
	void disable_wirte();
	void enable_all();
	void disable_all();
	void set_read_callback(Channel::EventCallBack callback);
	void set_write_callback(Channel::EventCallBack callback);
	void set_close_callback(Channel::EventCallBack callback);
	void set_error_callback(Channel::EventCallBack callback);
private:
	void update();
private:
	/**
	 * file descriptor
	 */
	int fd_ {-1};
	int index_ {-1};
	/**
	 * events the channel concerned about
	 */
	uint32_t events_ {0};
	/**
	 * active events returned from poller
	 */
	uint32_t revents_ {0};
	/**
	 * read callback
	 */
	Channel::EventCallBack read_callback;
	/**
	 * write callback
	 */
	Channel::EventCallBack write_callback;
	/**
	 * callback when connection closed
	 */
	Channel::EventCallBack close_callback;
	/**
	 * error callback
	 */
	Channel::EventCallBack error_callback;
	/**
	 * the event loop object
	 */
	EventLoop* event_loop_;
	static const uint32_t ReadEvent;
	static const uint32_t WriteEvent;
	static const uint32_t NoneEvent;
};
#endif // !defined(EA_DD6A6F05_C975_4f16_8268_198920A973BA__INCLUDED_)
