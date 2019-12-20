/*@brief:求解斐波那契数列*/
#include <iostream>
#include <ctime>
using namespace std;
//递归法求解
long long Fibonacci_solution1(int n)
{
      clock_t time_stt = clock();
      if(n == 0) return 0;
      if(n == 1) return 1;
      long long data = Fibonacci_solution1(n-1)+Fibonacci_solution1(n-2);
      cout<<"递归耗时:"<<1000*(clock()-time_stt)<<endl;
      return data;
}
//循环求解
long long Fibonacci_solution2(int n)
{
    clock_t time_stt = clock();
    if(n == 0) return 0;
    if(n == 1) return 1;
    long long fibN;
    long long fibOne = 1;
    long long fibTwo = 0;
    for(int i=2;i<=n;i++)
    {
        fibN = fibOne + fibTwo;
        fibTwo = fibOne;
        fibOne = fibN;
    }
    cout<<"循环耗时:"<<1000*(clock()-time_stt)<<endl;
    return fibN;
}
int main()
{
    int n;
    cin>>n;
    long long data1 = Fibonacci_solution1(n);
    long long data2 = Fibonacci_solution2(n);
    cout<<data1<<" "<<data2<<endl;
    return 0;
}