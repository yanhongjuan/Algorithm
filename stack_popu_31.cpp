/*@brief:给定两个序列,判断第二个序列是否是第一个序列弹出序列*/
/*@note:第一个序列的顺序为该序列的入栈顺序*/
#include <iostream>
#include <stack>
using namespace std;
bool Test(int *pPush,int *pPop,int n)
{
    bool beStack = false;
    const int *pNextpush = pPush;//下一个要压入辅助栈的元素
    const int *pNextpop = pPop;//序列2中下一个弹出的值
    stack<int> HelpStack;
    if(pNextpush != nullptr && pNextpop != nullptr && n>0)//前提条件
    {
        while(pNextpop-pPop < n)//只要还有未弹出的值则继续执行
        {
              while(HelpStack.empty() || HelpStack.top() != *pNextpop)
              {
                   if(pNextpush - pPush == n)//边界条件,序列1的值已经全部入栈过
                     break;
                   HelpStack.push(*pNextpush);
                   pNextpush++;
              }
              if(HelpStack.top() != *pNextpop)
              {
                 break; 
              }
              HelpStack.pop();
              pNextpop++;
        }
        if(HelpStack.empty() && pNextpop-pPop == n)
            beStack = true;
    }
    return beStack;
}
/*---------------------------------------测试代码-------------------------------------------------*/
void test1()
{
    int nLength = 5;
    int pPush[nLength] = {1,2,3,4,5};
    int pPop[nLength] = {4,5,3,2,1};
    bool beStack = Test(pPush,pPop,nLength);
    cout << beStack << endl;
}
void test2()
{
    int nLength = 1;
    int pPush[nLength] = {1};
    int pPop[nLength] = {1};
    bool beStack = Test(pPush,pPop,nLength);
    cout << beStack << endl;
}
void test3()
{
    int nLength = 2;
    int pPush[nLength] = {1,2};
    int pPop[nLength] = {2,1};
    bool beStack = Test(pPush,pPop,nLength);
    cout << beStack << endl;
}
void test4()
{
    int nLength = 5;
    int pPush[nLength] = {1,2,3,4,5};
    int pPop[nLength] = {4,5,3,1,2};
    bool beStack = Test(nullptr,nullptr,0);
    cout << beStack << endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}