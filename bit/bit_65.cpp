/*@brief:不使用四则运算实现两个数相加*/
#include <iostream>
using namespace std;
int sumData(int data1,int data2)
{
    int res1 = 0,res2 = 0;
    do{
    res1 = data1^data2;
    res2 = (data1&data2)<<1;
    data1 = res1;
    data2 = res2;
    }
    while(res2!=0);
    return res1;
}
int main()
{
    int data1,data2;
    cin>>data1>>data2;
    cout<<sumData(data1,data2)<<endl;
    return 0;
}