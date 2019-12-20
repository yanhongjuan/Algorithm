/*@brief:只有一个数字出现了一次,其他都出现了三次*/
#include <iostream>
#include <vector>
using namespace std;
int oneNum(vector<int> &vec)
{
    int n = vec.size();
    int res[32]{0};
    for(int i=0;i<n;i++)
    {
       int bit = 1;
       for(int j=31;j>=0;j--)
       {
           if(vec[i]&bit) 
              res[j]++;
            bit = bit<<1;
       }
    }
    int result = 0;
    for(int i =0;i<32;i++)
    {
        result = result<<1;//注意这里的处理,先左移再相加
        result +=res[i]%3;
    }
    return result;
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
    int data = oneNum(vec);
    cout<<data<<endl;
    return 0;
}