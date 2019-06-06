#ifndef JUPITER_EPOLLER_INCLUDE_H
#define JUPITER_EPOLLER_INCLUDE_H


#include <vector>
#include "Poller.h"

struct epoll_event;


namespace jupiter {



class EPoller: public Poller
{
    public:
        EPoller();
        ~EPoller() override;
        void UpdateChannel(Channel* channel) override;
        void RemoveChannel(Channel* channel) override;
        void Poll(ChannelList& active_channels, int timeout_ms) override;
    private:
        typedef std::vector<struct epoll_event> EventList;

        static const int InitEventListSize = 16;
        int efd;
        EventList events;
};




}



#endif

