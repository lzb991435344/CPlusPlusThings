#pragma once

#ifndef ADD_H
#define ADD_H

//C调用C++
//extern "C"在C中是语法错误，需要放在C++头文件中。
extern "C" {
	int add(int x, int y);
}
#endif
