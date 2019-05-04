#include <iostream>

#include "adapter.h"

int main(){
	
	adapter stAdapter;

	stAdapter.start_dev();
	stAdapter.start_process();
	stAdapter.stop_dev();
	
	std::cout<<"end ----!"<<std::endl;

#ifdef TEST_MACRO
	std::cout<<"compiler pass the args!"<<std::endl;
#endif
	
	return 0;
}

