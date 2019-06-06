#include <sys/epoll.h>
#include "EPoller.h"


namespace jupiter {





EPoller::EPoller():
    efd(epoll_create1(EPOLL_CLOEXEC)),
    events(InitEventListSize)
{
    if(efd < 0) {
        printf("[E] EPoller::EPoller epoll_create1\n");
    }
}

void EPoller::UpdateChannel(Channel* channel)
{
}

void EPoller::RemoveChannel(Channel* channel)
{
}

void EPoller::Poll(ChannelList& active_channels, int timeout_ms)
{
}




}
