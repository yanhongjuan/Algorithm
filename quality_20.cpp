/*@brief:判断一个字符串是否表示数值*/
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
bool scanUnsignInteger(char *&str)
{
    char *first = str;
    while(str!='\0' && *str>='0' && *str<='9') ++str;
    return str>first;//判断有没有数字
}
bool scanInteger(char *&str)
{
     if(*str == '+' || *str == '-') ++str;//有符号的数值
     return scanUnsignInteger(str);
}
bool isNum(char *str)
{
     if(str == nullptr) return false;
     bool numeric = scanInteger(str);//判断第一部分有没有整数
     if(*str == '.')
     {
         ++str;
         numeric = scanUnsignInteger(str) || numeric;//小数点前或后有数字都代表是数字
     }
     if(*str == 'e' || *str =='E')
     {
         ++str;
         numeric = numeric && scanInteger(str);//e或者E前面没有数字不能表示数值;e或者E之后,没有数字不能表示数值
     }
     return numeric && *str=='\0';
}
int main()
{
   string s;
   cin>>s;
   int n =s.size();
   char str[n+1];//这里必须指定大小,原因未知,不指定大小会导致段核心错误
   strcpy(str,s.c_str());
   cout<<isNum(str)<<endl;
   return 0;
}