/*@brief:实现正则表达式匹配*/
#include <iostream>
#include <string.h>
using namespace std;
bool matchCore(const char *str,const char *pattern)
{
    if(*str == '\0' && *pattern == '\0') return true;
    if(*str != '\0' && *pattern == '\0') return false;
    if(*(pattern+1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
           return matchCore(str+1,pattern+2)||matchCore(str+1,pattern)||matchCore(str,pattern+2);
           else
           {
               return matchCore(str,pattern+2);//略过一个
           }
           
    }
    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
    {
        return matchCore(str+1,pattern+1);
    }
    return false;
}
bool match(const char *str,const char *pattern)
{
    if(str == nullptr || pattern == nullptr) return false;
    return matchCore(str,pattern);
}
int main()
{
    const char *str1 = "aaa";//这里的const必须有
    const char *str2 = "a.a";
    const char *str3 = "ab*ac*a";
    const char *str4 = "aa.a";
    cout<<match(str1,str2)<<endl;
    cout<<match(str1,str3)<<endl;
    cout<<match(str1,str4)<<endl;
    return 0;
}
/*
char *可以转string,直接赋值就可以;
string转char *不可以直接转,有三种方式:c_str(),data(),copy()
①c_str()返回一个c风格的字符数组,带有'\0'结束符
②data()返回一个数组,不自动加'\0'
③copy()拷贝一块字符到新的内存,需要分配一块内存用于存放.
但是使用string转char *时最好不要直接赋值如下:
string str = "sss";
const char *p = str.c_str();
这样p最后指向一个垃圾地址因为str被析构使用strcpy()最好
*/