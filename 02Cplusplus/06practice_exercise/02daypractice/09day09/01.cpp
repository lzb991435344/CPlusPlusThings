#include<iostream>
using namespace std;

/**
1.catch捕获异常时，不会进行数据类型的默认转换。

2.限制异常的方法

当一个函数声明中不带任何异常描述时，它可以抛出任何异常。例如：
int f(int,char);                 //函数f可以抛出任何异常
在函数声明的后面添加一个throw参数表，在其中指定函数可以抛出的异常类型。例如：
int g(int,char)  throw(int,char);  //只允许抛出int和char异常。
指定throw限制表为不包括任何类型的空表，不允许函数抛出任何异常。如：
int h(int,char) throw();//不允许抛出任何异常

3.捕获所有异常 在多数情况下，catch都只用于捕获某种特定类型的异常，但它也具有捕获全部异常的能力。
其形式如下：

catch(…) {
	……                        //异常处理代码
}
4.再次抛出异常 如是catch块无法处理捕获的异常，它可以将该异常再次抛出，使异常能够在恰当的地方被处理。
再次抛出的异常不会再被同一个catch块所捕获，它将被传递给外部的catch块处理。要在catch块中再次抛出
同一异常，只需在该catch块中添加不带任何参数的throw语句即可。

5.异常的嵌套调用 try块可以嵌套，
即一个try块中可以包括另一个try块，这种嵌套可能形成一个异常处理的调用链。


*/

/***
int main() {
	cout << "1--befroe try block..." << endl;
	try {
		cout << "2--Inside try block..." << endl;
		throw 10;
		cout << "3--After throw ...." << endl;
	}
	catch (int i) {
		cout << "4--In catch block1 ... exception..errcode  is.." << i << endl;
	}
	catch (char * s) {
		cout << "5--In catch block2 ... exception..errcode is.." << s << endl;
	}
	cout << "6--After Catch...";
	system("pause");
	return 0;
}*/
/**
1--befroe try block...
2--Inside try block...
4--In catch block1 ... exception..errcode  is..10
6--After Catch...

*/