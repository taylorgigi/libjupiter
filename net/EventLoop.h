///////////////////////////////////////////////////////////
//  EventLoop.h
//  Implementation of the Class EventLoop
//  Created on:      26-ÆßÔÂ-2019 16:13:42
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_725F615B_5E13_49a8_8FE8_3E523CA88682__INCLUDED_)
#define EA_725F615B_5E13_49a8_8FE8_3E523CA88682__INCLUDED_

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
#endif // !defined(EA_725F615B_5E13_49a8_8FE8_3E523CA88682__INCLUDED_)
