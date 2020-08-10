#include <iostream>

using namespace std;

class singleton {
private:
	static singleton *p;
	singleton() {}
public:
	 singleton *instance();
};

 singleton *singleton::instance() {
	static singleton p;
	cout<< "i am a single"<<endl;
	return &p;
}
 /**
int main() {
	
	 singleton*  ss = NULL;
	 ss->instance();
	//ss->instance();
	return 0;
}*/
/**
i am a single
*/