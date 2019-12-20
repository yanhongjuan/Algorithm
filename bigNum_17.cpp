/*@brief:打印1到最大的n位数,比如:输入3则打印出1,2,3......一直到999*/
/*题目没有给出n的限制,所以是大数问题,n可能无限大,采用字符串的加法求解*/
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
bool Increment(char *number);
void PrintNumber(char *number);
void printToMax_1(int n)
{
    if(n<=0) return;
    char *number = new char[n+1];
    memset(number,'0',n);//必须进行初始值设定,因为后面是直接用这个值进行
    number[n]='\0';
    while(!Increment(number))//判断有没有达到最高位
    {
        PrintNumber(number);
    }
    cout<<endl;
    delete []number;
}
bool Increment(char *number)
{
    int nLen = strlen(number);
    bool isOverflow = false;
    int nTakeover = 0;//只有在最低位时它为0
    for(int i = nLen-1;i>=0;--i)
    {
        int nSum = number[i]-'0'+nTakeover;
        if(i==nLen-1) nSum++;
        if(nSum>=10)
        {
            if(i==0) isOverflow=true;//最低位为进位,则已经是最大值
            else
            {
                nSum = nSum-10;
                nTakeover = 1;
                number[i] = '0'+nSum;
            } 
        }
        else
        {
            number[i] = '0'+nSum;
            break;
        }
    }
    return isOverflow;
}
void PrintNumber(char *number)
{
    //一个一个打印,从第一个非0元素开始打印
     bool isBeging = true;//打印标志位
     int nLen = strlen(number);
     for(int i=0;i<nLen;i++)
     {
         if(isBeging && number[i]!='0') isBeging = false;
         if(!isBeging) cout<<number[i];
     }
     cout<<" ";
}
void printToMaxOfDigitsRecursively(char *number,int n,int index)
{
     if(index == n-1) 
     {
         PrintNumber(number);
         return;
     }
     for(int i=0;i<10;i++)
     {
         number[index+1] = i+'0';
         printToMaxOfDigitsRecursively(number,n,index+1);
     }
}
void printToMax_2(int n)
{
    if(n<=0) return;
    char *number = new char[n+1];
    number[n] = '\0';
    for(int i=0;i<10;i++)
    {
        number[0] = i+'0';//第一位的值
        printToMaxOfDigitsRecursively(number,n,0);
    }
    delete []number;
}
int main()
{
    int n;
    cin>>n;
    //printToMax_1(n);
    cout<<endl<<endl;
    printToMax_2(n);
    cout<<endl;
    return 0;
}
