#include "product.h"
#include "builder.h"
#include <iostream>

int mode_builder::builder::create_socket()
{
	//m_platform->create;桥接模式，但似乎网络这里的接口操作不好抽象。使用条件编译适配好了。
	m_product->iFd=1111;
	std::cout<<"builder::create_socket"<<std::endl;
	
	return 0;
}

int mode_builder::builder::set_socket_linger(int a, int b)
{
	std::cout<<"builder::set_socket_linger"<<std::endl;
	
	return 0;
}

int mode_builder::builder::test_dest_reachable(int a, int nb)
{
	std::cout<<"builder::test_dest_reachable"<<std::endl;
	
	return 0;
}

int mode_builder::udp_builder::create_socket()
{
	m_product->iFd=2222;
	std::cout<<"udp_builder::create_socket"<<std::endl;
	
	return 0;
}

int mode_builder::udp_builder::set_socket_linger(int a, int b)
{
	std::cout<<"udp_builder::set_socket_linger"<<std::endl;
	
	return 0;
}

int mode_builder::udp_builder::test_dest_reachable(int a, int nb)
{
	std::cout<<"udp_builder::test_dest_reachable"<<std::endl;
	
	return 0;
}

int mode_builder::tcp_builder::create_socket()
{
	m_product->iFd=3333;
	std::cout<<"tcp_builder::create_socket"<<std::endl;
	
	return 0;
}

int mode_builder::tcp_builder::set_socket_linger(int a, int b)
{
	std::cout<<"tcp_builder::set_socket_linger"<<std::endl;
	
	return 0;
}

int mode_builder::tcp_builder::test_dest_reachable(int a, int nb)
{
	std::cout<<"tcp_builder::test_dest_reachable"<<std::endl;
	
	return 0;
}