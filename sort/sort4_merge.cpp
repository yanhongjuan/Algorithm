/*@brief:归并排序,有序子序列的归并*/
/*采用分而治之的策略,分治法将问题分成一些小的问题,然后进行递归求解,治的阶段将分的阶段得到的答案修补在一起*/
/*时间复杂度为o(nlogn),固定的;是稳定算法*/
/*不是原地排序算法,空间复杂度是o(n)*/
#include <iostream>
#include <vector>
using namespace std;
void Merge(vector<int> &vec,int *res,int L,int R,int RightEnd)
{
    int tmp = L;
    int leftEnd = R;//前半段的最后位置
    int NumE = RightEnd-L+1;//待排元素总数
    while(L<leftEnd && R<=RightEnd)//左右两边的子序列都不为空时,取两个序列中较小的值放入辅助数组中
    {
        if(vec[L] <= vec[R])
            res[tmp++] = vec[L++];
        else
            res[tmp++] = vec[R++];    
    }
    //将剩余部分加入
    while(L<leftEnd) res[tmp++]=vec[L++];//左边有剩余元素
    while(R<=RightEnd) res[tmp++]=vec[R++];
    for(int i=0;i<NumE;i++,RightEnd--)//将辅助数组中排好序的元素赋值到原数组中
         vec[RightEnd] = res[RightEnd];
}
void Msort(vector<int> &vec,int *res,int L,int R)
{
    if(L == R) return;
       int mid = L + (R - L)/2;
       Msort(vec,res,L,mid);
       Msort(vec,res,mid+1,R);
       Merge(vec,res,L,mid+1,R);//对排好序的两部分进行合并
}
void MergeSort(vector<int> &vec,int n)
{
    int res[n];//这里开辟数组,在后面直接调用,避免递归过程中反复开辟数组空间
    Msort(vec,res,0,n-1);
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
    int length = vec.size();
    MergeSort(vec,length);//一般排序主函数中参数为两个,方便阅读
    for(int i=0;i<length;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}