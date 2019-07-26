///////////////////////////////////////////////////////////
//  EPoller.h
//  Implementation of the Class EPoller
//  Created on:      26-七月-2019 17:47:10
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_5E4BA1D6_C2B4_44ea_824F_7905EB2835B0__INCLUDED_)
#define EA_5E4BA1D6_C2B4_44ea_824F_7905EB2835B0__INCLUDED_

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
#endif // !defined(EA_5E4BA1D6_C2B4_44ea_824F_7905EB2835B0__INCLUDED_)
