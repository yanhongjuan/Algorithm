/*@brief:N皇后问题*/
//逐行搜索,每一行中皇后的位置
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<vector<string>> res;
    vector<bool> col,dal1,dal2;
    vector<string> generateBorad(int n,vector<int> row)
    {
         vector<string> board(n,string(n,'.'));
         for(int i=0;i<n;i++) board[i][row[i]] = 'Q';
         return board;
    }
    bool isvalid(int n,int x,int y,vector<string> &queen)
    {
         for(int i=0;i<n;i++)
         {
             if(queen[i][y] == 'Q') return false;
         }
         for(int i=x-1,j = y-1;i>=0&&j>=0;--i,--j)
         {
             if(queen[i][j] == 'Q') return false;
         }
         for(int i=x-1,j = y+1;i>=0&&j<n;--i,++j)
         {
             if(queen[i][j] == 'Q') return false;
         }
         return true;
    }
    //摆放第index行的位置
    void putQueen(int n,int index,vector<int>& row,vector<string> &queen)
    {
         if(index == n) //结束条件
         {
            res.push_back(generateBorad(n,row)); 
         }
         for(int i=0;i<n;i++)//看能不能将index行的皇后摆放在第i列
         {
            if(isvalid(n,index,i,queen))//不在同一列,同一斜对角线
            {
                 row.push_back(i);
                 queen[index][i] = 'Q';
                 putQueen(n,index+1,row,queen);
                 queen[index][i] = '.';
                 row.pop_back();
            } 
         }
    }
public:
    vector<vector<string>> solveNqueens(int n)
    {
        res.clear();
        vector<int> row;
        col = vector<bool>(n,false);//有n列
        dal1 = vector<bool>(2*n-1,false);//斜对角线元素有2*n-1个
        dal2 = vector<bool>(2*n-1,false);
        vector<string> queen(n,string(n,'.'));
        putQueen(n,0,row,queen);
        return res;
    }
};
int main()
{
    int n = 4;
    vector<vector<string>> res;
    res = Solution().solveNqueens(n);
    int k = res.size();
    for(int i=0;i<k;i++)
    {
        for(int j =0;j<n;j++)
        {
            cout<<res[i][j]<<endl;
        }
        cout<<endl;
    }
    return 0;
}