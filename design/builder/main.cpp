#include <iostream>

#include "product.h"
#include "builder.h"
#include "director.h"

#include "netData.h"

int main(){
	
	using namespace mode_builder;
	builder* builder = new tcp_builder();
	director* pdirector = new director(builder);

	pdirector->construct();
	
	product* product = builder->get_product();
	product->show();
	
	delete builder;
	delete pdirector;
	
	builder = new udp_builder();
	pdirector = new director(builder);
	pdirector->construct();
	product = builder->get_product();
	product->show();
	
	delete builder;
	delete pdirector;
	
	/*有种角色扮演的感觉，各司其职的清晰性*/

	//net data
	textHeader stTextHead(22,0);

	netData<textHeader,int> netProtocol(&stTextHead);

	netProtocol.netDataPrint();
	netData<textHeader,int>::innerClass::innerOperationB();
		
	netData<textHeader,int>::innerClass stInnerObj(&netProtocol);
	stInnerObj.innerOperationA();
	
	return 0;
}
