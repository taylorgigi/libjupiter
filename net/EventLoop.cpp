///////////////////////////////////////////////////////////
//  EventLoop.cpp
//  Implementation of the Class EventLoop
//  Created on:      26-七月-2019 17:47:12
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#include "Channel.h"
#include "EventLoop.h"


namespace {
    const int PollerTimeOutMs = 10000;
}


EventLoop::EventLoop(){

}


EventLoop::~EventLoop(){

}


/**
 * add/modify channel
 */
void EventLoop::update_channel(Channel* channel){
    poller->update_channel(channel);
}


/**
 * delete channel
 */
void EventLoop::remove_channel(Channel* channel){
    poller->remove_channel(channel);
}


/**
 * start event loop
 */
void EventLoop::loop(){
    while(!quit) {
        active_channels.clear();
        poll_return_time = poller->poll(PollerTimeOutMs, active_channels);
        for(Channel *channel : active_channels) {
            channel->handle_event();
        }
    }
    // to-do: debug log - loop quit
}


void EventLoop::stop(){
    if(!quit) {
        quit = true;
        // to-do: debug log - eventloop stoped
    }
}