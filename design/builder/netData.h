#include <iostream>

//const用法
//模板类
//类中的类，；对外，访问的接口数目；类中类的访问属性
//模板的static函数
//

template<typename header, class T>
class netData{
public:
	netData();
	netData(header* p){ pstHead = p;}

	void netDataPrint() const {pstHead->printInfo();}//这里添加const，是说不改变成员变量

private:
	header *pstHead;
	
	netData(const netData&);
	void operator=(const netData&);

public:
class innerClass{
public:
	innerClass(netData<header,T>* netData):m_netData(netData){};
		void innerOperationA();
		static void innerOperationB(){std::cout<<"innerOperationB:"<<std::endl;} //在这里实现
private:
    const netData<header, T>* m_netData;
};

};

template<typename header, class T>
void netData<header,T>::innerClass::innerOperationA()
{
	std::cout<<"innerOperationA:"<<std::endl;
	header::showClassInfo();
	//这里要使用this，否则编译报错，可以去掉试试
	this->m_netData->netDataPrint();
}

#if 0
//template<typename header, class T>
static void netData::innerClass::innerOperationB()
{
	std::cout<<"innerOperationB:"<<std::endl;
	//header::showClassInfo();

	//m_netData->netDataPrint();
}
#endif

class textHeader{
public:
	explicit textHeader();
	textHeader(int Seq, int bEnd_):iSeq(Seq),bEnd(bEnd_){};

	void printInfo(){
		std::cout<<"Protocol info:This is for reliable text transport in net!"<<std::endl;
		std::cout<<"The segment is explained below:iSeq is for sequence num,bEnd is for mark the last pkt!"<<std::endl;
		std::cout<<"seq num:"<<iSeq<<"  end:"<<bEnd<<std::endl;
	}

	static void showClassInfo(){
			std::cout<<"The class name is textHeader!"<<std::endl;
			std::cout<<"The class size is:"<<sizeof(textHeader)<<std::endl;
	}
	
private:
	int iSeq;
	bool bEnd;
	int *m_test; //	32、64位的指针
};

