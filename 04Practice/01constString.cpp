

#include <iostream>

using namespace std;

//字符串实际是指针，指向首地址

int main(){
    char *s="abcdefgh";
    //*s='p';  //编译顺利，运行崩溃..
    cout<<"abcde"+1<<endl;    //bcde
    cout<<*"abcde"<<endl;     //a
    cout<<*("abcde")<<endl;   //a
    cout<<s<<endl;               //abcdefgh
    cout<<"abcdefgh" + 7<<endl;    //h
    cout<<"abcdef"[3]<<endl;     //d
    cout<<*("abcdef" + 4)<<endl;   //e
    cout<<*"abcde"+2<<endl;      //99
    cout<<"c"<<endl;             //c
    cout<<'c'<<endl;             //c
    cout<<(int)'c'<<endl;        //99
    ///////////////////////
    int anum = 'a';
    cout<<anum<<endl;            //97

    char ach = 'a';
    cout<<ach<<endl;             //a
    //字符数组
    char ch[]="abcdefghijk";
    cout<<ch<<endl;              //abcdefghijk
    cout<<ch + 2<<endl;            //cdefghijk

    char str1[]       = "abc";
    char str2[]       = "abc";
    const char str3[] = "abc";
    const char str4[] = "abc";
    const char* str5  = "abc";
    const char* str6  = "abc";
    char* str7  = "abc";
    char* str8  = "abc";

    cout << ( str1 == str2 ) << endl; // 输出0
    cout << ( str3 == str4 ) << endl; // 输出0
    cout << ( str5 == str6 ) << endl; // 输出1
    cout << ( str7 == str8 ) << endl; // 输出1

    return 0;
}