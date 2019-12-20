/*@brief:冒泡排序算法实现*/
/*小的气泡往上跑,每次只判断相邻两个元素大小*/
/*①冒泡排序算法是一个原地排序算法,空间复杂度为o(1)*/
/*②冒泡排序算法是稳定的算法,值相同的元素在排序过程中不会改变它们的相对位置*/
/*③时间复杂度最好为o(n),最坏为o(n^2)*/
#include <iostream>
#include <vector>
using namespace std;
void BubbleSort(vector<int>& vec)
{
     int n = vec.size();
     for(int i=0;i<n;i++)
     {
         int flag = 0;
         for(int j = n-2;j>=i;j--)
         {
             if(vec[j] > vec[j+1])
             {
                flag = 1;
                swap(vec[j],vec[j+1]);
             }
         }
         if(flag == 0) break;
     }
}
int main()
{
    vector<int> vec;
    int n;
    while(cin>>n)
    {
       vec.push_back(n);
       if(cin.get()=='\n')
          break;
    }
    BubbleSort(vec);
    int len = vec.size();
    for(int i=0;i<len;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}