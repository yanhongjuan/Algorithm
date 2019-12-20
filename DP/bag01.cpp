/*@brief:01背包问题*/
//背包问题有两个约束条件,一个是物品数量,一个是背包容量

#include <iostream>
#include <vector>
using namespace std;
//背包问题的记忆化搜索解法
class Solution1
{
    private:
    vector<vector<int>> memo;//二维数组,因为一个解有两个约束条件,有重复子问题,用于保存子问题结果
    //用[0,....n-1]的物品填充容积为C的背包的最大价值
    int bestValue(const vector<int>& w,const vector<int>& v,int index,int C)
    {
        if(index<0 || C<=0) return 0;
        if(memo[index][C] != -1) return memo[index][C];
        int res = bestValue(w,v,index-1,C);
        if(C>=v[index])
        res = max(res,v[index]+bestValue(w,v,index-1,C-v[index]));
        memo[index][C] = res;
        return res;
    }
    public:
    int knapsack01(const vector<int>& w,const vector<int>& v,int C)
    {
        int n = w.size();
        memo = vector<vector<int>>(n,vector<int>(C+1,-1));
        
        return bestValue(w,v,n-1,C);
    }
};
//背包问题的动态规划解法
class Solution2
{
    public:
    int knapsack01(const vector<int>& w,const vector<int>& v,int C)
    {
        int n = w.size();
        if(n == 0 || C == 0) return 0;//没有物品
        vector<vector<int>> memo (2,vector<int>(C+1,-1));//进行优化,只需要两行即可,上面一行存储偶数行,下面一行存储奇数行
        for(int j=0;j<=C;j++)
        memo[0][j] = (j>=w[0] ? v[0] : 0);
        for(int i=1;i<n;i++)//物品数量
         for(int j =0;j<=C;j++)//容量
         {
             memo[i%2][j] = memo[(i-1)%2][j];
             if(j>=w[i]) memo[i%2][j] = max(memo[i%2][j],v[i]+memo[(i-1)%2][j-w[i]]);
         }
        return memo[(n-1)%2][C];
    }
};
int main()
{
  return 0;
}