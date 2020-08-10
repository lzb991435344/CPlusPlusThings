#include <iostream>
using namespace std;

//C++调用C
extern "C" {
	#include "add2.h"
}
/**
int main() {
	add(2, 3);
	return 0;
}*/