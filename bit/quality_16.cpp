/*@brief:程序实现数值的整数次方*/
/*考虑特殊情况:①指数为负数②底数为0时,指数也为负数*/
#include <iostream>
using namespace std;

bool invalidPut = false;//全局变量使得代码安全性更高,不只是返回结果,同时可以通过全局变量知道是无效输入返回0还是求得结果为0
/*double powerFinish(double base,int expo)
{
    double num = 1.0;
    for(int i=1;i<=expo;i++)
    {
        num = num*base;
    }
    return num;
}*/
//效率更高的实现乘方的方式
double powerFinish(double base,int expo)
{
    if(expo == 0) return 1;
    if(expo == 1) return base;//这里的边界条件,expo/2则expo至少是2起步
    int res = powerFinish(base,expo>>1);//右移运算符代替除2
    res = res*res;
    if(expo&1 == 1) res = res*base;//用与操作替换和2取余操作
    return res;
}
double powerCore(double base,int expo)
{
     invalidPut = false;
     if((base == 0.0) && (expo<0))
     {
         invalidPut = true;
         return 0;
     }
     int actualExpo = expo;
     if(expo<0) actualExpo = -expo;
     double res = powerFinish(base,actualExpo);
     if(expo<0) res = 1.0/res;
     return res;
}
int main()
{
    double base;
    int expo;
    cin>>base>>expo;
    double res = powerCore(base,expo);
    cout<<res<<endl;
    return 0;
}