/*@brief:希尔排序*/
/*目的:利用插入排序简单,同时克服插入排序每次只交换两个元素的缺点*/
/*定义增量序列,递减的序列间隔,最后间隔为1进行插入排序*/
/*更小间隔的排序任然保持上一间隔有序*/
/*适用于数据量大的排序*/
/*希尔排序的时间复杂度和增量序列有关,{1,2,4,8..}这种为o(n^2),它是不稳定排序*/
/*参考博客:https://blog.csdn.net/zpznba/article/details/88407089 但是程序是错的,增量错误*/
#include <iostream>
#include <vector>
using namespace std;
void shell_sort(vector<int> &vec,int n)
{
    int LenGap = 2;//
    int gap = n/LenGap;//下标增量
    while(gap>=1)
    {
        for(int i = gap;i<n;i++)
        {
            int num = vec[i];
            int j = i-gap;
            for(;j>=0;j=j-gap)
            {
                if(vec[j]>num)
                   vec[j+gap] = vec[j];
                else break;
            }
            vec[j+gap] = num;
        }
        gap = gap/LenGap;//缩小增量为上一个的一半
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
   int m = vec.size();
   shell_sort(vec,m);
   for(int i = 0;i<m;i++)
   {
       cout<<vec[i]<<" ";
   }
   cout<<endl;
   return 0;
}
