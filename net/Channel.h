///////////////////////////////////////////////////////////
//  Channel.h
//  Implementation of the Class Channel
//  Created on:      26-ÆßÔÂ-2019 16:12:58
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_84D3550B_E8B3_491d_9588_816110C00B64__INCLUDED_)
#define EA_84D3550B_E8B3_491d_9588_816110C00B64__INCLUDED_

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
	void index(int index_);
	int index();
	uint32_t events();
	void set_read_callback(EventCallBack callback);
	void set_write_callback(EventCallBack callback);
	void set_close_callback(EventCallBack callback);
	void set_error_callback(EventCallBack callback);
	void handle_event();
	void update();
	void remove();
	void enable_read();
	void disable_read();
	void enable_write();
	void disable_wirte();
	void enable_all();
	void disable_all();

private:
	/**
	 * file descriptor
	 */
	int fd_ = -1;
	int index_ = -1;
	/**
	 * events the channel concerned about
	 */
	uint32_t events_ = 0;
	/**
	 * active events returned from poller
	 */
	uint32_t revents_ = 0;
	/**
	 * read callback
	 */
	EventCallBack read_callback;
	/**
	 * write callback
	 */
	EventCallBack wirte_callback;
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
	EventLoop* event_loop_;

};
#endif // !defined(EA_84D3550B_E8B3_491d_9588_816110C00B64__INCLUDED_)
