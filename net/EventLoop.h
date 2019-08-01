///////////////////////////////////////////////////////////
//  EventLoop.h
//  Implementation of the Class EventLoop
//  Created on:      26-七月-2019 17:47:12
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#ifndef LIBJUPITER_NET_EVENT_LOOP_H
#define LIBJUPITER_NET_EVENT_LOOP_H

#include <memory>
#include "Poller.h"

class Poller;

class EventLoop
{

public:
	EventLoop();
	virtual ~EventLoop();

	void update_channel(Channel* channel);
	void remove_channel(Channel* channel);
	void loop();

private:
	std::unique_ptr<Poller> poller;
};

#endif // !defined(LIBJUPITER_NET_EVENT_LOOP_H)