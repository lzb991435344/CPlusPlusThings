#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;
/**
vector<string> read_lines_from_file(string &file_name) {
	vector<string> lines;
	string line;

	ifstream file_handle(file_name.c_str());
	while (file_handle.good() && !file_handle.eof()) {
		getline(file_handle, line);
		lines.push_back(line);
	}

	file_handle.close();

	return lines;
}
vector<string> * read_lines_from_file1(string &file_name) {
	vector<string> * lines;
	string line;

	ifstream file_handle(file_name.c_str());
	while (file_handle.good() && !file_handle.eof()) {
		getline(file_handle, line);
		lines->push_back(line);
	}

	file_handle.close();

	return lines;
}
vector<string> * read_lines_from_file1_1(string &file_name) {
	vector<string> * lines = new vector<string>;
	string line;

	ifstream file_handle(file_name.c_str());
	while (file_handle.good() && !file_handle.eof()) {
		getline(file_handle, line);
		lines->push_back(line);
	}

	file_handle.close();

	return lines;
}*/

/**
int main() {
	// get file name from the first argument
	string file_name("/home/light/CLionProjects/Morden_C++/CMakeLists.txt");
	int count = read_lines_from_file(file_name).size();
	cout << "File " << file_name << " contains " << count << " lines.";

	cout << endl;
	//    string file_name1 ("/home/light/CLionProjects/Morden_C++/CMakeLists.txt");
	//    int count1 = read_lines_from_file1(file_name1)->size();
	//    cout << "File " << file_name << " contains " << count1 << " lines.";
	string file_name1("/home/light/CLionProjects/Morden_C++/CMakeLists.txt");
	int count1 = read_lines_from_file1_1(file_name1)->size();
	cout << "File " << file_name << " contains " << count1 << " lines.";
	return 0;
}*/