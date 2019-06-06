#ifndef JUPITER_POLLER_INCLUDE_H
#define JUPITER_POLLER_INCLUDE_H

#include <boost/noncopyable.hpp>
#include <unordered_map>
#include <vector>

namespace jupiter {


class Channel;


class Poller: public boost::noncopyable
{
    public:
        typedef std::vector<Channel*> ChannelList;

        Poller();
        virtual ~Poller();
        virtual void UpdateChannel(Channel* channel) = 0;
        virtual void RemoveChannel(Channel* channel) = 0;
        virtual void Poll(ChannelList& active_channels, int timeout_ms) = 0;
    protected:
        typedef std::unordered_map<int,Channel*> ChannelMap;
        ChannelMap channels;
};






}


#endif

