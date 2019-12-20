/*@brief:动态规划之爬楼梯*/
/*①使用直接递归求解,会有大量重复计算,可以画图看出*/
/*②使用记忆式搜索的方式会使得空间复杂度增大*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    private:
    vector<int> memo;
    int calcWays(int n)
    {
        if(n == 0 || n == 1)
        return 1;
        if(memo[n]==-1)
         memo[n] = calcWays(n-1)+calcWays(n-2);
         return memo[n];
    }
    public:
    int climbStairs(int n)
    {
       memo = vector<int>(n+1,-1);
       return calcWays(n); 
    }
};
int main()
{
   cout<<Solution().climbStairs(3)<<endl;
   return 0;
}
/*
动态规划的方法实现:
int calcWays(int n)
    {
        vector<int> memo(n+1,-1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i=2;i<=n;i++)
           memo[i] = memo[i-1]+memo[i-2];
        return memo[i];
    }
*/