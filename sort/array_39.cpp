/*@brief:数组中出现次数超过一半的数字*/
/*借助了快速排序的思想,每次排序后左边的数比选择数字小,右边数字比选择的数字大,如果是超过一半的数字
则下标为中间值的数一定是出现一半的数字,最后进行一个判断即可*/
#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &vec,int start,int end)
{
    int temp = vec[start];
    int i = start;
    int j = end;
    while(i<j)
    {
        while(i<j && vec[j]>temp) j--;
        if(i<j) vec[i++] = vec[j];
        while(i<j && vec[i]<temp) i++;
        if(i<j) vec[j--] = vec[i];
    }
        vec[i] = temp;
        return i;
}
int MoreThanHalfNum_Solution(vector<int> numbers) 
{
    int n = numbers.size();
    //这里的边界条件是重点
    if(n<1) return 0;
    if(n == 1) return numbers[0];
    int mid = n/2;
    int start = 0;
    int end = n-1;
    int index = partition(numbers,start,end);
    while(index != mid)
    {
        if(index>mid)
        {
            end = index-1;
            index = partition(numbers,start,end);
        }
            else
            {
                start = index+1;
                index = partition(numbers,start,end);
            }
        }
        int res = numbers[mid];
        int count = 0;
        //这里的判断条件不可以缺少
        for(int i =0;i<=n;i++)
        {
            if(numbers[i] == res) count++;
        }
        if(count>mid)
        return res;
        else return 0;
    }
int main()
{
    int k;
    vector<int> numbers;
    while(cin>>k)
    {
        numbers.push_back(k);
        if(cin.get() == '\n')
          break;
    }
    cout<<MoreThanHalfNum_Solution(numbers)<<endl;
    return 0;
}