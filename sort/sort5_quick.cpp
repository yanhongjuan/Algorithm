/*@brief:快速排序*/
/*快速排序的基本思想是,通过一趟排序将要排序的数据分割成独立的两部分,其中一部分的所有数据都比另一部分的所有数据都要小*/
/*然后再按此方法对这两部分数据分别进行快速排序,以此整个数据变成有序序列*/
/*是一种原地不稳定的排序算法,时间复杂度为o(nlogn)*/
/*理解参考:https://www.cnblogs.com/xc90/articles/9665516.html*/
//挖坑填数的方法
//快速排序比归并排序常用,它的空间复杂度更小
#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& vec,int left,int right)
{
    int i = left;
    int j = right;
    int temp = vec[left];//基准数
    while(i<j)
    {
        while(i<j&&vec[j]>temp) j--;
        if(i<j) vec[i++] = vec[j];
        while(i<j&&vec[i]<temp) i++;
        if(i<j) vec[j--] = vec[i];
    }
    vec[i] = temp;
    return i;
}
void quick_sort(vector<int> &vec,int left,int right)
{
    if(left > right) return;
    int nex = partition(vec,left,right);//找到基准值的位置
    quick_sort(vec,left,nex-1);
    quick_sort(vec,nex+1,right);
}
void QuickSort(vector<int> &vec,int n)
{
    quick_sort(vec,0,n-1);
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
    int len = vec.size();
    QuickSort(vec,len);
    for(int i = 0;i<len;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}