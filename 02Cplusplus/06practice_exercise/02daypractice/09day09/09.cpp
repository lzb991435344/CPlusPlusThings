#include<iostream>
using namespace std;

class BasicException {
public:
	char* Where() { return (char*)"BasicException..."; }
};

class FileSysException :public BasicException {
public:
	char *Where() { return (char*)"FileSysException..."; }
};

class FileNotFound :public FileSysException {
public:
	char *Where() { return (char*)"FileNotFound..."; }
};

class DiskNotFound :public FileSysException {
public:
	char *Where() { return (char*)"DiskNotFound..."; }
};

/**
int main() {
	try {
		//         .....  //
		throw FileSysException();
	}
	catch (DiskNotFound p) { cout << p.Where() << endl; }
	catch (FileNotFound p) { cout << p.Where() << endl; }
	catch (FileSysException p) { cout << p.Where() << endl; }
	catch (BasicException p) { cout << p.Where() << endl; }

	try {
		//        .....  //
		throw DiskNotFound();
	}
	catch (BasicException p) { cout << p.Where() << endl; }
	catch (FileSysException p) { cout << p.Where() << endl; }
	catch (DiskNotFound p) { cout << p.Where() << endl; }
	catch (FileNotFound p) { cout << p.Where() << endl; }
}*/
/**
FileSysException...
BasicException...
*/