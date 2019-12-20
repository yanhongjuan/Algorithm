/*@brief:二维数组行递增,列递增,找到该数组中是否存在给定数*/
/*思想:右上角值与给定值比较*/
#include <iostream>
#include <vector>
using namespace std;
bool FoundFigure(int *mat,int rows,int columns,int number)
{
    int row = 0;
    int col = columns-1;
    while(row < rows && col>=0)
    {
        int res = mat[row*rows+col];//二维数组转化为一维数组进行操作
        if(res == number) return true;
        else
        {
            if(res > number) --col;
            else
            {
                ++row;
            }
            
        }
        
    }
    return false;
}
int main()
{
    int n;
    int matrix[][4]={{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool yexit = FoundFigure((int *)matrix,4,4,15);
    cout<<yexit<<endl;
}