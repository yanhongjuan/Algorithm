/*@brief:求一个数二进制表示中1的个数*/
/*右移一个数字,如果是一个无符号数值,则用0填补最左边的n位,如果是一个有符号的数值,则用数字的符号位填补最左边的n位*/
/*此题要考虑为负数的情况,如果直观的求解与最右边一位做与运算,则负数右移可能会导致死循环,全都是1*/
#include <iostream>
using namespace std;
int bitNum(int data)
{
    int flag = 1;
    int count = 0;
    while(flag)
    {
        int res = data&flag;//只有flag最高位为1
        if(res) count++;
        flag=flag<<1;//会一直左移32位
    }
    return count;
}
/*这种解法是减去1后与原来的整数做位与运算,相当于把整数中最右边的1变成0,是很多二进制的思路*/
 int bitNum2(int data)
 {
     int count=0;
     while(data)
     {
         count++;
         data = (data-1)&data;
     }
     return count;
 }
int main()
{
    int data;
    cin>>data;
    cout<<bitNum(data)<<endl;//解法1,左移标志位
    cout<<bitNum2(data)<<endl;//解法2,减1之后与原数据相与
    return 0;
}