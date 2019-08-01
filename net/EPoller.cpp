///////////////////////////////////////////////////////////
//  EPoller.cpp
//  Implementation of the Class EPoller
//  Created on:      26-七月-2019 17:47:10
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#include <sys/epoll.h>
#include "EPoller.h"


namespace {
	const int ChannelNew = -1;
	const int ChannelAdded = 1;
	const int ChannelDeleted = 2;
}


EPoller::EPoller(int timeout_): efd(epoll_create1(EPOLL_CLOEXEC)), events(InitEventListSize){
}


EPoller::~EPoller(){

}


/**
 * update channel
 */
void EPoller::update_channel(Channel* channel){
	int op = 0;
	const int index = channel->index();
	const int fd = channel->fd();
	switch(index) {
		case ChannelNew:
		case ChannelDeleted:
			channels[fd] = channel;
			channel->index(ChannelAdded);
			update(EPOLL_CTL_ADD, channel);
			break;
		case ChannelAdded:
			if(channels.find(fd) != channels.end() && channels[fd] == channel){
				if(channel->events() == Channel::NoneEvent){
					channel->index(ChannelDeleted);
					update(EPOLL_CTL_DEL, channel);
				}
				else {
					update(EPOLL_CTL_MOD, channel);
					// to-do: debug log
				}
			}
			else {
				// to-do: error log
			}
			break;
		default:
			// to-do: error log
	}
}


/**
 * delete channel
 */
void EPoller::remove_channel(Channel* channel){

}


/**
 * get active channels
 */
uint64_t EPoller::poll(int timeout, ChannelList& active_channels){
	return  0;
}


/**
 * update(internal)
 */
void EPoller::update(int op, Channel *channel){
	int fd = channel->fd();
	struct epoll_event event;
	event.events = channel->events();
	event.data.ptr = channel;
	if(epoll_ctl(efd, op, &event) < 0) {
		// to-do: error log
	}
}
