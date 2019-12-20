/*@brief:最大连续子序列的和*/
/*tip:数组中有正数也有负数*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) 
    {
        int len = array.size();
        if(len < 1) return 0;
        if(len == 1) return array[0];
        int maxArray = array[0];
        int res[len];
        res[0] = array[0];
        for(int i = 1;i<len;i++)
        {
            res[i] = max(array[i],res[i-1]+array[i]);
            if(res[i]>maxArray) maxArray = res[i];
        }
        return maxArray;
    }
};
int main()
{
   Solution sol;
   int k;
   vector<int> vec;
   while(cin>>k)
   {
       vec.push_back(k);
       if(cin.get() == '\n') break;
   }
   cout<<sol.FindGreatestSumOfSubArray(vec)<<endl;
   return 0;
}