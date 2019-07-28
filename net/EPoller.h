///////////////////////////////////////////////////////////
//  EPoller.h
//  Implementation of the Class EPoller
//  Created on:      26-七月-2019 17:47:10
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#ifndef LIBJUPITER_NET_EPOLLER_H
#define LIBJUPITER_NET_EPOLLER_H

#include <vector>
#include <list>
#include "Poller.h"

class Channel;

struct epoll_event;

class EPoller : public Poller
{
public:
	EPoller();
	~EPoller();

	void update_channel(Channel* channel) override;
	void remove_channel(Channel* channel) override;
	uint64_t poll(ChannelList& active_channels) override;
private:
	void update(int op, Channel* channel);
private:
	/**
	 * initial event list size
	 */
	static const int InitEventListSize {16};

	/**
	 * descriptor of epoll
	*/
	int efd {0};

	/**
	 * event epoll returns
	 */
	std::vector<struct epoll_event> events;
};
#endif // !defined(LIBJUPITER_NET_EPOLLER_H)
