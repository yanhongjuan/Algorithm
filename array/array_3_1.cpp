/*@brief:返回数组中重复的一个数字*/
#include <iostream>
#include <unordered_map>
using namespace std;
int duplicate(int numbers[],int length)
{
    int max = -1;
    /*判断输入的数字是否在范围内*/
    if(numbers == NULL || length <= 0)
    {
        return -1;
    }
    for(int i = 0;i<length;i++)
    {
        if(numbers[i] < 0 || numbers[i] > length-1) return -1;
    }
    /*思想①:将每个值调整到它的正确位置上,如果对应位置已经有正确的值,则为重复元素*/
    for(int i =0;i < length;i++)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                return numbers[i];
            }
            int tmp = numbers[i];
            numbers[i] = numbers[tmp];//这里注意
            numbers[tmp] = tmp;
        } 
    }
    return max;
    /*思想②:哈希表,将每个值作为关键字判断,如果之前已经出现该关键字则重复
    unordered_map<int,int> res;
    for(int i=0;i<length;i++)
       {
           if(!res.count(numbers[i]))//返回哈希表中关键字为numbers[i]的个数
               res[numbers[i]] = i;
            else
            {
                return numbers[i];
            }
       }
       return -1;  */
}
/*-------------------------------------测试程序--------------------------------------------*/
void test1()
{
    int numbers[] = {2,1,0,1,4,4};
    int n = sizeof(numbers)/sizeof(int);
    int t = duplicate(numbers,n);
    cout<<t<<endl;
}
void test2()
{
    int numbers[] = {1,5,2,3,2,3};
    int n = sizeof(numbers)/sizeof(int);
    int t = duplicate(numbers,n);
    cout<<t<<endl;
}
void test3()
{
    int numbers[] = {2,1,0,3,4};
    int n = sizeof(numbers)/sizeof(int);
    int t = duplicate(numbers,n);
    cout<<t<<endl;
}
void test4()
{
    int numbers[] = {1};
    int n = sizeof(numbers)/sizeof(int);
    int t = duplicate(numbers,n);
    cout<<t<<endl;
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}