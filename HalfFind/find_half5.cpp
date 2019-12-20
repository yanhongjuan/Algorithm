/*@brief:查找最后一个小于等于给定值的元素*/
#include <iostream>
#include <vector>
using namespace std;
int find_half(vector<int> vec,int data,int n)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low+((high-low)>>1);
        if(vec[mid]<=data)
        {
            if((mid == n-1) || (vec[mid+1]>data)) return mid; 
            else low = mid+1;
        }
        else high = mid-1;
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
    int k = find_half(vec,data,len);
    cout<<k<<endl;
    return 0;
}