///////////////////////////////////////////////////////////
//  EPoller.cpp
//  Implementation of the Class EPoller
//  Created on:      26-七月-2019 17:47:10
//  Original author: Yang Shengming
///////////////////////////////////////////////////////////

#include <sys/epoll.h>
#include "EPoller.h"


EPoller::EPoller(int timeout_): efd(epoll_create1(EPOLL_CLOEXEC)), events(InitEventListSize){
}


EPoller::~EPoller(){

}


/**
 * update channel
 */
void EPoller::update_channel(Channel* channel){

}


/**
 * delete channel
 */
void EPoller::remove_channel(Channel* channel){

}


/**
 * get active channels
 */
uint64_t EPoller::poll(ChannelList& active_channels){

	return  0;
}


/**
 * update(internal)
 */
void EPoller::update(int op, Channel* channel){

}
