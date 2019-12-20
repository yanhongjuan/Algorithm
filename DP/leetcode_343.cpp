/*@brief:整数分割后的乘积最大*/
/*先确定递归终止条件*/
//①记忆化搜索的方式求解
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solutin
{
    private:
        vector<int> memo;
    int breakInteger(int n)
    {
        if(n == 1) return 1;
        int res = -1;
        if(memo[n] != -1) return memo[n];
        for(int i=1;i<=n-1;i++)
        {
            //这里因为可能就拆了两个数,所以要和i*(n-i)比较.这里注意条件:将其至少拆分为两个整数的和
           res = max(res,max(i*breakInteger(n-i),i*(n-i)));
        }
        memo[n] = res;
        return res;
    }
    public:
    int integerBreak(int n)
    {
        memo = vector<int>(n+1,-1);
        return breakInteger(n);
    }
};
/*②动态规划求解*/
class Solutin
{
    private:
        vector<int> memo;
    int breakInteger(int n)
    {
        memo[0] = 0;
        memo[1] = 1;
        for(int i=2;i<=n;i++)//求解memo[i]
        {
            for(int j =1;j<=i-1;j++)
            {
                memo[i] = max(memo[i],max(j*(i-j),j*memo[i-j]));
            }
        }
        return memo[n];
    }
    public:
    int integerBreak(int n)
    {
        memo = vector<int>(n+1,-1);
        return breakInteger(n);
    }
};