/*@brief:堆排序:选择排序的一种改进*/
/*原地不稳定,时间复杂度为o(nlogn)*/
/*理解过程参考:https://www.cnblogs.com/wanglei5205/p/8733524.html*/
#include <iostream>
#include <vector>
using namespace std;
void HeapBuild(vector<int> &vec,int len,int index)//采用递归方式构建堆,只考虑单子树的情况即可
{
     int MaxIndex = index;
     int LeftIndex = index*2+1;
     int RightIndex = index*2+2;
     if(LeftIndex<len && vec[LeftIndex]>vec[MaxIndex]) MaxIndex = LeftIndex;
     if(RightIndex<len && vec[RightIndex]>vec[MaxIndex]) MaxIndex = RightIndex;
     if(MaxIndex!=index) 
     {
       swap(vec[MaxIndex],vec[index]);
       HeapBuild(vec,len,MaxIndex);//上面大根堆排好序,下面乱序了,所以递归进行
     }
}
/*第一次从底向上构建大根堆,之后开始剪枝的时候从顶向下构建*/
void heap_sort(vector<int> &vec,int len)
{
    for(int i = len/2-1;i>=0;i--)//从第一个非叶子结点开始构建大根堆,自底向上
    {
        HeapBuild(vec,len,i);//i为父结点
    }
    for(int i = len-1;i>=1;i--)//进行堆排序,每次都剪去最大的元素
    {
        swap(vec[0],vec[i]);
        HeapBuild(vec,i,0);//再次构建大根堆,每次都逻辑删除最后一个元素,所以长度在变化
    }
}
int main()
{
    int k;
    vector<int> vec;
    while(cin>>k)
    {
        vec.push_back(k);
        if(cin.get()=='\n')
           break;
    }
    int len = vec.size();
    heap_sort(vec,len);
    for(int i= 0;i<len;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}