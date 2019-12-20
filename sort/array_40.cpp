/*@brief:最小的k个数*/
/*采用大根堆的方式,先在一个大小为k的容器中放入k个元素,然后构建大根堆,每次将堆顶元素和下一个元素比较,小则换入重建大根堆,否则删除*/
#include <iostream>
#include <vector>
using namespace std;
void HeapBuild(vector<int> &vec,int k,int index)
{
    int MaxIndex = index;
    int LeftIndex = index*2+1;
    int RightIndex = index*2+2;
    if(LeftIndex<k && vec[LeftIndex]>vec[MaxIndex]) MaxIndex = LeftIndex;
    if(RightIndex<k && vec[RightIndex]>vec[MaxIndex]) MaxIndex = RightIndex;
    if(MaxIndex != index)
    {
        swap(vec[MaxIndex],vec[index]);
        HeapBuild(vec,k,MaxIndex);
    }
}
void heap_sort(vector<int> &vec,int k)
{
    for(int i = k/2-1;i>=0;i--)
    {
        HeapBuild(vec,k,i);
    }
}
vector<int> GetLeastNumbers_Solution(vector<int> &vec,int k)
{
    int n = vec.size();
    vector<int> out;
    if(n<1 || k<=0 || k>n) return out;//这里的边界条件一定要注意
    if(k == n) return vec;
    int flag = n-1;
    for(int i=0;i<k;i++)
    {
        out.push_back(vec[i]);
    }
    heap_sort(out,k);
    for(int i = k;i<n;i++)
    {
        if(vec[i] < out[0]) 
        {
            out[0] = vec[i];
            heap_sort(out,k);
        }
    }
    return out;
}
int main()
{
    int val;
    int k;
    vector<int> vec;
    vector<int> output;
    while(cin>>val)
    {
        vec.push_back(val);
        if(cin.get()=='\n')
          break;
    }
    cin>>k;
    output = GetLeastNumbers_Solution(vec,k);
    int n = output.size();
    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}