///////////////////////////////////////////////////////////
//  EPoller.h
//  Implementation of the Class EPoller
//  Created on:      26-ÆßÔÂ-2019 16:13:28
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_D327A46F_339B_41d9_9565_D6366336848D__INCLUDED_)
#define EA_D327A46F_339B_41d9_9565_D6366336848D__INCLUDED_

#include "Poller.h"

class EPoller : public virtual Poller
{

public:
	EPoller();
	virtual ~EPoller();

	virtual void update_channel(Channel* channel);
	virtual void remove_channel(Channel* channel);
	virtual uint64_t poll(ChannelList& active_channels);

private:
	/**
	 * event epoll returns
	 */
	vector<struct epoll_event events> events;

	void update(int op, Channel* channel);

};
#endif // !defined(EA_D327A46F_339B_41d9_9565_D6366336848D__INCLUDED_)
