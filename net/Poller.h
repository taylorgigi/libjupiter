///////////////////////////////////////////////////////////
//  Poller.h
//  Implementation of the Class Poller
//  Created on:      26-ÆßÔÂ-2019 16:13:15
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_81671B74_FFD8_4f47_9571_88C162661CB0__INCLUDED_)
#define EA_81671B74_FFD8_4f47_9571_88C162661CB0__INCLUDED_

class Poller
{

public:
	Poller();
	virtual ~Poller();
	virtual void update_channel(Channel* channel);
	virtual void remove_channel(Channel* channel);
	virtual uint64_t poll(ChannelList& active_channels);

protected:
	ChannelMap channels;

};
#endif // !defined(EA_81671B74_FFD8_4f47_9571_88C162661CB0__INCLUDED_)
