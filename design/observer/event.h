
#include <list>

class event_observer{
public:
	enum{
		CHAN_CREATE,
		CHAN_DESTROY;
	};
	
	virtual int event_proc(int iEventType) = 0;
};

class observer_net:public event_observer{
	
	virtual int event_proc(int iEventType);
};

class observer_sc:public event_observer{
	
	virtual int event_proc(int iEventType);
};

class observer_dec:public event_observer{
	
	virtual int event_proc(int iEventType);
};


class event_msg{
public:
	
	event_msg();
	~event_msg();
	
	int EventReg(event_observer*);
	int EventUnreg(event_observer*);
	
	int EventMsgRecv(int iEventType);
	
private:
	std::list<event_observer*> m_listEvent;
};