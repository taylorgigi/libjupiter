///////////////////////////////////////////////////////////
//  Poller.h
//  Implementation of the Class Poller
//  Created on:      26-七月-2019 17:47:08
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#if !defined(EA_52BAEB18_6469_450f_BA29_567563FBAC2F__INCLUDED_)
#define EA_52BAEB18_6469_450f_BA29_567563FBAC2F__INCLUDED_

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
#endif // !defined(EA_52BAEB18_6469_450f_BA29_567563FBAC2F__INCLUDED_)
