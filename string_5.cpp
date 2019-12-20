/*@brief:字符串中的空格用指定串代替*/
#include <iostream>
#include <string>
using namespace std;
void ReplaceBlank(char str[],int len)
{
    if(str == nullptr || len<=0) return;
    int numberofBlank = 0;
    int originalLen = 0;
    int i = 0;
    while(str[i]!='\0')
    {
        ++originalLen;
        if(str[i] == ' ') ++numberofBlank;
        ++i;
    }
    int newLen = originalLen+numberofBlank*2;//新的长度,加上结束符刚好是最后一个下标
    int indexofOriginal = originalLen;
    int indexofNew = newLen;
    while(indexofOriginal>=0 && indexofNew>indexofOriginal)
    {
        if(str[indexofOriginal] == ' ')
        {
             str[indexofNew--] = '0';
             str[indexofNew--] = '2';
             str[indexofNew--] = '%';
        }
        else
        {
            str[indexofNew--] = str[indexofOriginal];
        }
        --indexofOriginal;
    }
    cout<<str<<endl;
}
int main()
{
    const int len = 100;
    char str[len] = "hello world";//字符数组表示一个字符串
   // cin>>str;//带空格的字符串不能用cin输入,cin遇空白停止,包括空格等
    cout<<str<<endl;
    ReplaceBlank(str,len);
    return 0;
}