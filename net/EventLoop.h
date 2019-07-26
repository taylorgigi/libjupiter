///////////////////////////////////////////////////////////
//  EventLoop.h
//  Implementation of the Class EventLoop
//  Created on:      26-七月-2019 17:47:12
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_35A87C75_6714_456f_8A41_A97D279BC92F__INCLUDED_)
#define EA_35A87C75_6714_456f_8A41_A97D279BC92F__INCLUDED_

#include "Poller.h"

class EventLoop
{

public:
	EventLoop();
	virtual ~EventLoop();
	Poller *m_Poller;

	void update_channel(Channel* channel);
	void remove_channel(Channel* channel);
	void loop();

private:
	Poller poller;

};
#endif // !defined(EA_35A87C75_6714_456f_8A41_A97D279BC92F__INCLUDED_)
