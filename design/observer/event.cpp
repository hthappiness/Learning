#include "event.h"

#include <iostream>

event_msg::event_msg()
{
	event_observer* pNetObserver = new observer_net;
	event_observer* pScObserver  = new observer_sc;
	event_observer* pDecObserver = new observer_dec;
	
	EventReg(pDecObserver);
	EventReg(pScObserver);
	EventReg(pNetObserver);
}

event_msg::~event_msg()
{
	event_observer* pstTmpObserver;
	std::list<event_observer*>::iterator it = m_listEvent.begin();
	for( ; it!=m_listEvent.end(); it++ )
	{
		pstTmpObserver = *it;
		delete pstTmpObserver;
	}
}

int event_msg::EventReg(event_observer* pstObserver)
{
	m_listEvent.push_back(pstObserver);
	
	return 0;
}

int event_msg::EventUnreg(event_observer* pstObserver)
{
	event_observer* pstTmpObserver;
	std::list<event_observer*>::iterator it = m_listEvent.begin();
	for( ; it!= m_listEvent.end(); it++ )
	{
		pstTmpObserver = *it;
		if( pstObserver == pstTmpObserver)
		{
			return 0;
		}
	}
	
	return 1;
}

int event_msg::EventMsgRecv(int iEventType)
{
	event_observer* pstTmpObserver;
	std::list<event_observer*>::iterator it = m_listEvent.begin();
	for( ; it!=m_listEvent.end(); it++ )
	{
		pstTmpObserver = *it;
		pstTmpObserver->event_proc(iEventType);	
	}
	
	return 0;
}

int observer_net::event_proc(int iEventType)
{
	if( iEventType == CHAN_CREATE)
	{
		std::cout<<"create net!"<<std::endl;
	}
	else if ( iEventType == CHAN_DESTROY)
	{
		std::cout<<"destroy net!"<<std::endl;
	}
	else{
		std::cout<<"invalid Event Id!"<<iEventType<<std::endl;
	}
	
	return 0;
}

int observer_sc::event_proc(int iEventType)
{
	if( iEventType == CHAN_CREATE)
	{
		std::cout<<"create sc!"<<std::endl;
	}
	else if ( iEventType == CHAN_DESTROY)
	{
		std::cout<<"destroy sc!"<<std::endl;
	}
	else{
		std::cout<<"invalid Event Id!"<<iEventType<<std::endl;
	}
	
	return 0;
}

int observer_dec::event_proc(int iEventType)
{
	if( iEventType == CHAN_CREATE)
	{
		std::cout<<"create dec!"<<std::endl;
	}
	else if ( iEventType == CHAN_DESTROY)
	{
		std::cout<<"destroy dec!"<<std::endl;
	}
	else{
		std::cout<<"invalid Event Id!"<<iEventType<<std::endl;
	}
	
	return 0;
}