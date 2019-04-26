#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

namespace mode_builder{

class director{
	
private:
	builder *m_pBuilder;
	
public:
	director(builder *builder) { m_pBuilder = builder; }
	
	int construct(){
		m_pBuilder->create_product();
		m_pBuilder->create_socket();
		m_pBuilder->set_socket_linger(0, 0);
		m_pBuilder->test_dest_reachable(0, 0);
		
		return 0;
	};
};

}
#endif