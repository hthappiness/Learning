#ifndef __PRODUCT__H__
#define __PRODUCT__H__

namespace mode_builder{

class builder;
class udp_builder;
class tcp_builder;

class product{
public:

	product(){}
	void show();
	friend class builder;
	
	friend class udp_builder;
	friend class tcp_builder;
	
	product(const product&);
	void operator=(const product&);
private:
	int iFd;
};

}

#endif