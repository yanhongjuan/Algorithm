/*@brief:栈实现进制转换*/
#include <iostream>
#include <stack>
using namespace std;
stack<int> convert(int dig,int n)
{
    stack<int> stackReault;
    static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(dig > 0)
    {
        stackReault.push(dig%n);
        dig = dig/n;
    }
    return stackReault;
}
int main()
{
    int dig,lam;
    cin>>dig>>lam;
    stack<int> stackResult;
    stackResult=convert(dig,lam);
    while(!stackResult.empty())
    {
        cout<<stackResult.top();
        stackResult.pop();
    }
    cout<<endl;
}