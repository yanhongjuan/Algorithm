/*@brief:简单选择排序算法*/
/*思想:每次选择未排序部分的最小值与待排序位置的元素进行交换*/
/*它是一种原地排序算法,时间复杂度为o(n^2)*/
/*选择排序算法是一种不稳定算法,当选择最小值进行交换后可能会导致相同元素的位置发生变化*/
#include <iostream>
#include <vector>
using namespace std;
void SelectSort(vector<int> &vec)
{
    int n = vec.size();
    int min;
    for(int i = 0;i<n;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(vec[j]<vec[min])
               min = j;
        }
        if(i != min)
         swap(vec[i],vec[min]);
    }
}
int main()
{
    vector<int> vec;
    int n;
    while(cin>>n)
    {
        vec.push_back(n);
        if(cin.get() == '\n')
          break;
    }
    SelectSort(vec);
    int nn = vec.size();
    for(int i=0;i<nn;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}