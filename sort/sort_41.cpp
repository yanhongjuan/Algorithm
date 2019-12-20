/*@brief:数据流中的中位数使用STL实现*/
/*采用构建堆的方式,中位数的左边元素都小于右边元素,而中位数为左边元素的最大值,为右边元素的最小值
所以左边元素构建大根堆,右边元素构建小根堆*/
//规则:①如果此时元素个数为偶数或为空,则插入小根堆中,如果为奇数个,则插入大根堆中
//规则:②大根堆中元素小于小根堆中所有元素
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<double> min;
    vector<double> max;
public:
    void Insert(int num)
    {
        int n1 = min.size();
        int n2 = max.size();
        int n = n1 + n2;
        if((n&1) == 1)//当前元素有奇数个,则插入大根堆中;确保大根堆中元素小于小根堆的最小值
        {
            if(n1>0 && num>min[0])
            {
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());//greater<T>()为构建小根堆;less为构建大根堆;头文件为#include <algorithm>
                num = min[0];
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(),max.end(),less<int>());
        }
        else
        {
            if(n2>0 && num<max[0])//当前元素有偶数个,则插入小根堆中;确保小根堆中元素大于大根堆的最大值
            {
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
                num = max[0];
                pop_heap(max.begin(),max.end(),less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(),min.end(),greater<int>());
        }
    }

    double GetMedian()
    { 
        int n1 = min.size();
        int n2 = max.size();
        int n = n1 + n2;
        double res = 0;
        if(n == 0) return 0;
        if((n&1) == 0)//为偶数
            res = (min[0]+max[0])/2;
        else
            res = min[0];
        return res;
    }
};
int main()
{
    Solution sol;
    int k;
    while(cin>>k)
    {
        sol.Insert(k);
        if(cin.get()=='\n') break;
    }
    cout<<sol.GetMedian()<<endl;
    return 0;
}