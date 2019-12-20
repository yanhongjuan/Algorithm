/*@brief:两个排序数组合并为一个有序数组*/
#include <iostream>
#include <cstring>
using namespace std;
void sortArray(int *a,int *b,int lena,int lenb,int lenc)
{
   // int lena = sizeof(a);//8,因为这里的a不再是数组类型,而是指针
   //  int lenb = sizeof(b);//8
    int j = lena-1;//a的下标值
    int k = lenb-1;//b的下标值
    for(int i = lenc-1;i>=0;i--)
    {
        while(j<0&&k>=0) a[i] = b[k--];//如果b剩余,将b中元素插入到a中 
        if(a[j]>b[k]) a[i] = a[j--]; 
        else
        {
            a[i] = b[k--];
        } 
    }
    for(int i = 0;i<lenc;i++)
    {
        cout<<a[i]<<"";
    }
    cout<<endl;
}
void test1()
{
    int a[100] = {1,2,3,4};
   // int lena = sizeof(a);//400,数组的sizeof
   //int lena = strlen(a)/sizeof(int); 无法求数组中有效元素的个数,因为strlen是求字符数组有效个数的函数
    int b[] = {2,4,5,6};
    sortArray(a,b,4,4,8);
}
int main()
{
    test1();
    return 0;
}