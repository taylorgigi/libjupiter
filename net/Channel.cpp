///////////////////////////////////////////////////////////
//  Channel.cpp
//  Implementation of the Class Channel
//  Created on:      26-ÆßÔÂ-2019 16:12:58
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#include "Channel.h"


Channel::Channel(){

}





Channel::Channel(int fd__, EventLoop* event_loop__){

}


Channel::~Channel(){

}


/**
 * return file descriptor
 */
int Channel::fd(){

	return 0;
}


/**
 * set index
 */
void Channel::index(int index_){

}


/**
 * return index
 */
int Channel::index(){

	return 0;
}


/**
 * return events concerned about
 */
uint32_t Channel::events(){

	return  NULL;
}


/**
 * set read callback
 */
void Channel::set_read_callback(EventCallBack callback){

}


/**
 * set write callback
 */
void Channel::set_write_callback(EventCallBack callback){

}


/**
 * set close callback
 */
void Channel::set_close_callback(EventCallBack callback){

}


/**
 * set error callback
 */
void Channel::set_error_callback(EventCallBack callback){

}


/**
 * handle events returned from looper
 */
void Channel::handle_event(){

}


/**
 * updae channel
 */
void Channel::update(){

}


/**
 * remove channel from event loop
 */
void Channel::remove(){

}


/**
 * open read event
 */
void Channel::enable_read(){

}


/**
 * close read event
 */
void Channel::disable_read(){

}


/**
 * open write event
 */
void Channel::enable_write(){

}


/**
 * close write event
 */
void Channel::disable_wirte(){

}


/**
 * open read and write event
 */
void Channel::enable_all(){

}


/**
 * close read and write event
 */
void Channel::disable_all(){

}