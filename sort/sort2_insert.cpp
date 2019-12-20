/*@brief:插入排序*/
/*①比较元素②移动数据*/
/*基本思路就是:取出当前待排序的元素,和之前排好序的元素比较,如果当前元素小就把排好序的元素后移,类似于扑克牌洗牌操作*/
/*①插入排序是原地排序算法,不需要额外的存储空间.空间复杂度是o(1)*/
/*②插入排序是稳定的排序算法,保持值相同元素的顺序不变*/
/*③时间复杂度最好为o(n),最坏为o(n^2)*/
#include <iostream>
#include <vector>
using namespace std;
void InsertSort(vector<int>& vec)
{
    int n = vec.size();
    for(int i=0;i<n;i++)//待排序区间起始
    {
        int e = vec[i];//取出当前待排序元素值
        int j =i-1;
        for(;j>=0;j--)//排好序的区间范围
        {
            if(vec[j] > e)
               vec[j+1] = vec[j];//因为前面已经排好序了,如果当前元素比e大,则一定是从最后一个元素开始的
            else break;//找到位置,因为已经从小到大排好序了
        }
        vec[j+1] = e;
    }
}
int main()
{
    int n;
    vector<int> vec;
    while(cin>>n)
    {
        vec.push_back(n);
        if(cin.get()=='\n')
           break;
    }
    InsertSort(vec);
    int nn = vec.size();
    for(int i =0;i<nn;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}