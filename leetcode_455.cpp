/*@brief:分饼干让最多小朋友开心*/
/*采用贪心算法求解*/
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    //贪心算法和排序分不开,和每次取最大/最小是分不开的
    //每次取最大的饼干给最贪心的小朋友,如果最大的饼干都无法满足的话,这个小朋友就无法被满足
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         int n = g.size();
         int m = s.size();
         sort(g.begin(),g.end(),greater<int>());//sort改为降序排序的方式,加第三个参数
         sort(s.begin(),s.end(),greater<int>());
         int si =0,gi = 0;
         int res = 0;//记录结果
         while(gi<n&&si<m)
         {
             if(s[si]>=g[gi]) 
             {
                 res++;
                 si++;
                 gi++;
             }
             else
             gi++;//最大的饼干无法满足最贪心的小朋友,则小朋友加1
         }
         return res;
    }
};