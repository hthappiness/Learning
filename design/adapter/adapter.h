#include <iostream>

class Hi3559Dev{
public:
	Hi3559Dev(){}
	~Hi3559Dev(){}
	int start_Hi3559Dev(){
		std::cout<<"start Hi3559!!!"<<std::endl;
		}
	int stop_Hi3559Dev(){
		std::cout<<"stop Hi3559!!!"<<std::endl;
		}
	int start_process(){
		std::cout<<"start process Hi3559!!!"<<std::endl;
		}
};

class Hi3536Dev{
public:
	Hi3536Dev(){}
	~Hi3536Dev(){}
	int start_Hi3536Dev(){
		std::cout<<"start Hi3536!!!"<<std::endl;
		}
	int stop_Hi3536Dev(){
		std::cout<<"stop Hi3536!!!"<<std::endl;
		}
	int start_process(){
		std::cout<<"start process Hi3536!!!"<<std::endl;
		}
};

class adapter{
public:
	int start_dev(){
		m_Hi3556Dev.start_Hi3536Dev();
	}
	int stop_dev(){
		m_Hi3556Dev.stop_Hi3536Dev();
	}
	int start_process(){
		m_Hi3556Dev.start_process();
	}
	int GetResult(){
		std::cout<<"Not implemented!!!"<<std::endl;
		return 0;
	}
private:
	Hi3536Dev m_Hi3556Dev;
	Hi3559Dev m_Hi3559Dev;
};
