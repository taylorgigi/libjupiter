///////////////////////////////////////////////////////////
//  Channel.h
//  Implementation of the Class Channel
//  Created on:      26-七月-2019 17:47:05
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#ifndef LIBJUPITER_NET_CHANNEL_H
#define LIBJUPITER_NET_CHANNEL_H

#include <cstdint>
#include <functional>

namespace jupiter {

class EventLoop;

class Channel
{
public:
	typedef std::function<void(void)> EventCallBack;
    static const uint32_t ReadEvent;
    static const uint32_t WriteEvent;
    static const uint32_t NoneEvent;

	Channel(int fd__, EventLoop* event_loop__);
	~Channel();
	int fd();
	void index(int index__);
	int index();
	uint32_t events();
	void revents(uint32_t v);
	void set_read_callback(EventCallBack callback);
	void set_write_callback(EventCallBack callback);
	void set_close_callback(EventCallBack callback);
	void set_error_callback(EventCallBack callback);
	void handle_event();
	void remove();
	void enable_read();
	void disable_read();
	void enable_write();
	void disable_wirte();
	void enable_all();
	void disable_all();
private:
	void update();

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
	EventCallBack read_callback;
	/**
	 * write callback
	 */
	EventCallBack write_callback;
	/**
	 * callback when connection closed
	 */
	EventCallBack close_callback;
	/**
	 * error callback
	 */
	EventCallBack error_callback;
	/**
	 * the event loop object
	 */
	EventLoop* event_loop_ {nullptr};
};

} //namespace jupiter

#endif // !defined(LIBJUPITER_NET_CHANNEL_INCLUDE)
