///////////////////////////////////////////////////////////
//  EPoller.cpp
//  Implementation of the Class EPoller
//  Created on:      26-七月-2019 17:47:10
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#include <chrono>
#include <cerrno>
#include <sys/epoll.h>
#include "Channel.h"
#include "EPoller.h"


namespace {
	const int ChannelNew = -1;
	const int ChannelAdded = 1;
	const int ChannelDeleted = 2;
}

namespace jupiter {


EPoller::EPoller(): efd(epoll_create1(EPOLL_CLOEXEC)), events(InitEventListSize){
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
			else
				; // to-do: error log
			break;
		default:
			; // to-do: error log
	}
}


/**
 * delete channel
 */
void EPoller::remove_channel(Channel* channel){
	int fd = channel->fd();
	auto it = channels.find(fd);
	if(it != channels.end() && it->second == channel) {
		channels.erase(fd);
		int index = channel->index();
		if(index == ChannelAdded)
			update(EPOLL_CTL_DEL, channel);
		channel->index(ChannelNew);
		// to-do: debug log
	}
	else if(it->second != channel)
		; // to-do: error log
	else
		; // to-do: error log
}


/**
 * get active channels
 */
std::chrono::steady_clock::time_point EPoller::poll(int timeout, ChannelList& active_channels){
	int num = epoll_wait(efd, &*events.begin(), events.size(), timeout);
	std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
	if(num > 0) {
		fill_active_channels(num, active_channels);
		if(num == events.size())
			events.resize(events.size()*2);
	}
	else if(num == 0)
		; // to-do: debug log
	else if(num < 0 && errno != EINTR) {
		; // to-do: error log
	}
	return  now;
}


/**
 * fill active channels(internal)
 */
void EPoller::fill_active_channels(int num, ChannelList& active_channels){
	for(int i=0; i<num; ++i) {
		Channel* channel = static_cast<Channel*>(events[i].data.ptr);
		channel->revents(events[i].events);
		active_channels.push_back(channel);
	}
}


/**
 * update(internal)
 */
void EPoller::update(int op, Channel *channel){
	int fd = channel->fd();
	struct epoll_event event;
	event.events = channel->events();
	event.data.ptr = channel;
	if(epoll_ctl(efd, op, fd, &event) < 0) {
		; // to-do: error log
	}
}

} //namespace jupiter


