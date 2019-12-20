/*@brief:旋转数组的最小数字*/
#include <iostream>
#include <vector>
using namespace std;
int MinInOrder(vector<int> vec,int index1,int index2)
{
    int result = vec[index1];
    for(int i = index1+1;i<=index2;i++)
    {
        if(result > vec[i])
        result = vec[i];
    }
    return result;
}
int Min(vector<int> vec,int len)
{
    int index1 = 0;
    int index2 = len-1;
    int indexmid = index1;
    while(vec[index1] >= vec[index2])
    {
        if(index2-index1 == 1)
        {
            indexmid = index2;
            break;
        }
        indexmid = index1 + (index2-index1)/2;
        if(vec[index1] == vec[index2] && vec[indexmid] == vec[index1]) 
          return MinInOrder(vec,index1,index2);
        if(vec[indexmid]>=vec[index1]) index1 = indexmid;
        else if(vec[indexmid]<=vec[index2]) index2 = indexmid;
    }
    return vec[indexmid];
}
int main()
{
    int k;
    vector<int> vec;
    while(cin>>k)
    {
       vec.push_back(k);
       if(cin.get()=='\n')
        break;
    }
    int len = vec.size();
    int n = Min(vec,len);
    cout<<n<<endl;
    return 0;
}