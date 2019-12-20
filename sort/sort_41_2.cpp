/*@brief:数据流的中位数,自己实现堆排序*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    vector<double> min;
    vector<double> max;
public:
    void heap_pop_min(vector<double> &minn)
    {
        int n = minn.size();
        swap(minn[0],minn[n-1]);
        HeapBuildMin(minn,n-1,0);//自顶向下
    }
    void heap_pop_max(vector<double> &maxx)
    {
        int n = maxx.size();
        swap(maxx[0],maxx[n-1]);
        HeapBuildMax(maxx,n-1,0);
    }
    void HeapBuildMin(vector<double> &minn,int len,int index)
    {
        int MinIndex = index;
        int LeftIndex = index*2+1;
        int RightIndex = index*2+2;
        if(LeftIndex<len && minn[LeftIndex]<minn[MinIndex]) MinIndex = LeftIndex;
        if(RightIndex<len && minn[RightIndex]<minn[MinIndex]) MinIndex = RightIndex;
        if(MinIndex != index)
        {
            swap(minn[MinIndex],minn[index]);
            HeapBuildMin(minn,len,MinIndex);
        }
    }
    void HeapBuildMax(vector<double> &maxx,int len,int index)
    {
        int MaxIndex = index;
        int LeftIndex = index*2+1;
        int RightIndex = index*2+2;
        if(LeftIndex<len && maxx[LeftIndex]>maxx[MaxIndex]) MaxIndex = LeftIndex;
        if(RightIndex<len && maxx[RightIndex]>maxx[MaxIndex]) MaxIndex = RightIndex;
        if(MaxIndex != index)
        {
            swap(maxx[MaxIndex],maxx[index]);
            HeapBuildMax(maxx,len,MaxIndex);
        }
    }
    void heap_sort_min(vector<double> &minn)
    {
        int n = minn.size();
        for(int i=n/2-1;i>=0;i--)
        {
            HeapBuildMin(minn,n,i);
        }
    }
    void heap_sort_max(vector<double> &maxx)
    {
        int n = maxx.size();
        for(int i=n/2-1;i>=0;i--)
        {
            HeapBuildMax(maxx,n,i);
        }
    }
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
                heap_sort_min(min);
                num = min[0];//需要取最小的元素放入大根堆
                heap_pop_min(min);
                min.pop_back();//将尾部元素删除
            }
            max.push_back(num);
            heap_sort_max(max);//构建大根堆
        }
        else
        {
            if(n2>0 && num<max[0])//当前元素有偶数个,则插入小根堆中;确保小根堆中元素大于大根堆的最大值
            {
                max.push_back(num);
                heap_sort_max(max);
                num = max[0];
                heap_pop_max(max);
                max.pop_back();
            }
            min.push_back(num);
            heap_sort_min(min);//构建小根堆
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