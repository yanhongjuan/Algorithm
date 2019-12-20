/*@brief:最长上升子序列*/
//Lis(i):表示以第i个数字结尾的最长上升子序列的长度,num[i]必须被选取
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
    int lengthofLis(vector<int>& nums)
    {
        int n =nums.size();
        int res = 1;
        if(n == 0) return 0;
        vector<int> memo(n,1);//memo[i]表示以nums[i]结尾的最长上升子序列的长度
        for(int i=1;i<n;i++)//没有从0开始是因为当i=0时长度为1,memo[0]已经为1
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                  memo[i] = max(memo[i],1+memo[j]);
            }
        }
        for(int i=0;i<n;i++)
        {
             res = max(res,memo[i]);
        }
        return res;
    }
};
int main()
{
    int k;
    vector<int> nums;
    while(cin>>k)
    {
        nums.push_back(k);
        if(cin.get()=='\n')
         break;
    }
    cout<<Solution().lengthofLis(nums)<<endl;
   return 0;

}