///////////////////////////////////////////////////////////
//  Channel.cpp
//  Implementation of the Class Channel
//  Created on:      26-七月-2019 17:47:05
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#include "Channel.h"
#include "EventLoop.h"
#include <poll.h>

const uint32_t Channel::NoneEvent = 0;
const uint32_t Channel::ReadEvent = (POLLIN | POLLPRI);
const uint32_t Channel::WriteEvent = POLLOUT;

Channel::Channel(int fd__, EventLoop* event_loop__): fd_(fd__),event_loop_(event_loop__){

}


Channel::~Channel(){

}


/**
 * return file descriptor
 */
int Channel::fd(){
	return fd_;
}


/**
 * set index
 */
void Channel::index(int index__){
	index_ = index__;
}


/**
 * return index
 */
int Channel::index(){
	return index_;
}


/**
 * return events concerned about
 */
uint32_t Channel::events(){
	return  events_;
}


/**
 * set events returned from epoll
 */
void Channel::revents(uint32_t v){
	revents_ = v;
}


/**
 * set read callback
 */
void Channel::set_read_callback(Channel::EventCallBack callback){
	read_callback = callback;
}


/**
 * set write callback
 */
void Channel::set_write_callback(Channel::EventCallBack callback){
	write_callback = callback;
}


/**
 * set close callback
 */
void Channel::set_close_callback(Channel::EventCallBack callback){
	close_callback = callback;
}


/**
 * set error callback
 */
void Channel::set_error_callback(Channel::EventCallBack callback){
	error_callback = callback;
}


/**
 * handle events returned from looper
 */
void Channel::handle_event(){
	if((revents_ & POLLHUP) && !(revents_ & ReadEvent) && close_callback)
		close_callback();
	if ((revents_ & (POLLERR | POLLNVAL)) && error_callback)
		error_callback();
	if((revents_ & (ReadEvent | POLLRDHUP)) && read_callback)
		read_callback();
	if((revents_ & WriteEvent) && write_callback)
		write_callback();
}


/**
 * updae channel
 */
void Channel::update(){
	event_loop_->update_channel(this);
}


/**
 * remove channel from event loop
 */
void Channel::remove(){
	event_loop_->remove_channel(this);
}


/**
 * open read event
 */
void Channel::enable_read(){
	events_ |= ReadEvent;
	update();
}


/**
 * close read event
 */
void Channel::disable_read(){
	events_ &= ~ReadEvent;
	update();
}


/**
 * open write event
 */
void Channel::enable_write(){
	events_ |= WriteEvent;
	update();
}


/**
 * close write event
 */
void Channel::disable_wirte(){
	events_ &= ~WriteEvent;
	update();
}


/**
 * open read and write event
 */
void Channel::enable_all(){
	events_ |= (ReadEvent | WriteEvent);
	update();
}


/**
 * close read and write event
 */
void Channel::disable_all(){
	events_ &= (~ReadEvent & ~WriteEvent);
	update();
}
