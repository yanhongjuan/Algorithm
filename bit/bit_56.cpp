/*@brief:数组中只出现一次的两个数字*/
#include <iostream>
#include <vector>
using namespace std;
//找第一个结果中为1的位,表示异或结果是1则代表两个数字不同的位,一个为1一个为0,以此为分界线划分
unsigned int FindFirstBitLs(int num)
{
    int index = 0;
    while(((num&1)==0)&&(index<8*sizeof(int)))
    {
         num = num>>1;
         ++index;
    }
    return index;
}
bool IsBit(int num,int dex)
{
    num = num>>dex;
    return num&1;//注意这里加括号
}
void twiceData(vector<int>& vec,int *a)
{
     int n =vec.size();
     int res = 0;
     for(int i =0;i<n;i++)
     {
        res = vec[i]^res;
     }
     unsigned int index = FindFirstBitLs(res);
     for(int i =0;i<n;i++)
     {
        if(IsBit(vec[i],index))
           a[0] = a[0]^vec[i];
        else
           a[1] = a[1]^vec[i];  
     }
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
    int a[2]{0};
    twiceData(vec,a);
    cout<<a[0]<<endl<<a[1]<<endl;
    return 0;
}