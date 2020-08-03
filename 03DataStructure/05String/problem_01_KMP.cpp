#include <iostream>

using namespace std;



//测试未完成

int* getNextArray(char ms[] ) {
	int* res = { 0 };
	if (strlen(ms) == 1) {
		res[0] = -1;
		return res;
	}

	int next[20] = {0};
	next[0] = -1;
	next[1] = 0;
	int pos = 2;
	int cn = 0;
	while (pos < strlen(ms)) {
		if (ms[pos - 1] == ms[cn]) {
			next[pos++] = ++cn;
		}
		else if (cn > 0) {//字符不等
			cn = next[cn];
		}
		else {//字符不等， cn = 0
			next[pos++] = 0;
		}
	}
	return next;
}


int getIndexOf(string s, string m) {
	if (s.size() < 0 || m .size() < 0 ||s.length() < 1 || s.length() < m.length()) {
		return -1;
	}
	//int slen = s.size();
	char ss[10] = {0};
	//memcpy(ss, s.c_str(), s.length()); 
	char ms[10] = {0};
	//memcpy(ms, m.c_str(), m.length());

	int si = 0;
	int mi = 0;

	int* next = getNextArray(ms);

	while (si < strlen(ss) && mi <strlen(ms)) {
		if (ss[si] == ms[mi]) {
		//if(strcmp(ss[si], ms[mi])){
			mi++;
			si++;
		}
		else if (next[mi] == -1) {
			si++;
		}
		else {
			mi = next[mi];
		}

	}
	return mi == strlen(ms) ? si - mi : -1;
}
/**
int main() {
	string str = "abcabcababaccc";
	string match = "ab";

	cout << getIndexOf(str, match)<<endl;

	getchar();
	system("pause");
	return 0;
}*/