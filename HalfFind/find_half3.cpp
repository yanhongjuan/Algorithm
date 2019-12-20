/*@brief:二分查找变体--查找最后一个值等于给定值的元素*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_half(vector<int> vec,int n,const int data)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low+((high-low)>>1);
        if(vec[mid]>data) high = mid-1;
        else
        {
            if(vec[mid]<data) low = mid+1;
            else
            {
                if((mid == n-1) || (vec[mid+1]!=data)) return mid;//对原始二分法的改进
                else
                {
                    low = mid+1;
                } 
            }   
        } 
    }
    return -1;
}
int main()
{
    int data,value;
    cin>>data;
    vector<int> vec;
    while(cin>>value)
    {
        vec.push_back(value);
        if(cin.get()=='\n')
           break;
    }
    int len = vec.size();
    int n = find_half(vec,len,data);
    cout<<n<<endl;
    return 0;
}