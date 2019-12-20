/*@brief:测试指针是否占内存*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    char* str3 = "hello world";
    char* str4 = "hello world";
    
    cout<<str3<<endl;
    cout<<*str4<<endl;
    if(str1 == str2) cout<<"str1 and str2 are same"<<endl;
    else
        cout<<"str1 and str2 are diffrent"<<endl;
    if(str3 == str4) cout<<"str3 and str4 are same"<<endl;
    else
    {
        cout<<"str3 and str4 are diffrent"<<endl;
    }
    return 0;  
}