///////////////////////////////////////////////////////////
//  Poller.h
//  Implementation of the Class Poller
//  Created on:      26-七月-2019 17:47:08
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#ifndef LIBJUPITER_NET_POLLER_H
#define LIBJUPITER_NET_POLLER_H

#include <cstdint>
#include <list>
#include <unordered_map>

namespace {
	const int
}

class Channel;

class Poller
{

public:
	typedef std::list<Channel*> ChannelList;
	typedef std::unordered_map<int, Channel*> ChannelMap;

	Poller() = default;
	virtual ~Poller() = default;
	virtual void update_channel(Channel* channel) = 0;
	virtual void remove_channel(Channel* channel) = 0;
	virtual uint64_t poll(ChannelList& active_channels) = 0;
protected:
	ChannelMap channels;
};
#endif // !defined(LIBJUPITER_NET_POLLER_H)
