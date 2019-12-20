/*@brief:二分查找*/
/*①时间复杂度为o(logn)②只能用在数据是通过顺序表(数组)来存储的数据结构上*/
/*③针对一个有序的数据集合,通过和中间元素对比,将待查找的额区间缩小为之前的一半,直到找到要查找的元素*/
/*④适用于插入删除操作不频繁,一次排序多次查找的场景中,不适用于动态数据查找*/
/*⑤数据量太小/大不适合于二分查找*/
/*二分查找更适用于近似查找问题,接下来的变种问题*/
#include <iostream>
using namespace std;
int find_half(int *a,int low,int high,int data)
{  
    if(low>high) return -1;
    int mid = low +((high-low)>>1);
    if(a[mid] == data) return mid;
    else if(a[mid]>data) find_half(a,low,mid-1,data);
    else if(a[mid]<data) find_half(a,mid+1,high,data);
}
int main()
{
   int a[] = {1,2,5,6,9,11,55,62,411};
   int n = sizeof(a)/sizeof(int);
   int data;
   cin>>data;
   int low = 0;
   int high = n-1;
  /* while(low<=high)
   {
       int mid = low + (high-low)/2;
       //int nid = low+((high-low)>>1); 最优写法,位运算比除法运算快
       if(a[mid] == data) 
       {
           cout<<mid<<endl;
           break;
       }
       else
       {
           if(a[mid] > data) high = mid-1;//注意这里如果写成high=mid则会出现死循环
           else
           {
               low = mid+1;
           }  
       }  
   }*/
   //递归写法
   int res = find_half(a,low,high,data);
   cout<<res<<endl;
   return 0;
}