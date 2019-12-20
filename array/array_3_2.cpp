/*@brief:不修改数组找出重复的数字*/
/*在长度为n+1的数组里所有数字的大小都在1~n之间,所以至少有一个数字重复*/
/*注意局部变量值的更新,使用变量时考虑其值是否变化*/
#include <iostream>
using namespace std;
/*思路:采用二分法的思路,但是这种方法不能找出所有重复的数字*/
int getDuplication(int a[],int n)
{
    if(a == nullptr || n <= 0)
      return -1;
    int left = 1;
    int right = n-1;
    
    while(left <= right)//这里left和right代表的是具体的值,不是下标
    {
    int count = 0;
    int mid = left + (right-left)/2;
    for(int i = 0;i < n;i++)//这里粗心写成了<=n
    {
        //这里之前写成了a[i]<=mid && a[i]>=left可是这里的left已经变化导致出错,注意细节问题
        //如果判断条件为两个,则下面的范围都需要修改
         if(a[i] <= mid) count++;
    }  
    if(left == right) 
      { 
        if(count > mid) 
           return left;
        else
           break;
      }
    if(count > mid)
        right = mid;
    else
        left = mid+1;
    }
     return -1;    
}
/*----------------------------测试代码-----------------------------*/
void test1()
{
    int a[] = {2,3,5,4,3,2,6,7};
    int length = sizeof(a)/sizeof(int);
    int res = getDuplication(a,length);
    cout << res << endl;
}
void test2()
{
    int a[] = {5,4,3,6,2,1,4};
    int length = sizeof(a)/sizeof(int);
    int res = getDuplication(a,length);
    cout << res << endl;
}

void test3()
{
    int a[] = {4,4,4,4,5,6,7,5};
    int length = sizeof(a)/sizeof(int);
    int res = getDuplication(a,length);
    cout << res << endl;
}
void test4()
{
    int a[] = {};
    int length = sizeof(a)/sizeof(int);
    int res = getDuplication(a,length);
    cout << res << endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}