#ifndef __BUILDER__H__
#define __BUILDER__H__

#include "product.h"

namespace mode_builder{

//class product;
/*行为共性*/
class builder{
public:
		builder(){}
		virtual ~builder(){delete m_product;}
		virtual int create_product(){m_product = new product; return 0;}
		product* get_product(){return m_product;}
		
		virtual int create_socket();
		virtual int set_socket_linger(int, int);
		virtual int test_dest_reachable(int, int);
//private:
protected:
		product *m_product;
};

class udp_builder:public builder{
public:
	virtual int create_product(){ return builder::create_product();}
	virtual int create_socket();
	virtual int set_socket_linger(int, int);
	virtual int test_dest_reachable(int, int);
};

class tcp_builder:public builder{
public:
	virtual int create_product(){return builder::create_product();}
	virtual int create_socket();
	virtual int set_socket_linger(int, int);
	virtual int test_dest_reachable(int, int);
};

}

#endif
