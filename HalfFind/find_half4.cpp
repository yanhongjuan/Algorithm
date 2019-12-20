/*@brief:查找第一个大于等于给定值的元素*/
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
        if(vec[mid]<data) low = mid+1;
        else if(vec[mid]>=data)
        {
            if((mid == 0) || (vec[mid-1]<data)) return mid;
            else high = mid-1;
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