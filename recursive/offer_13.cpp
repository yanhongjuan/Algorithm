/*@brief:回溯算法之机器人的运动范围*/
#include <iostream>
using namespace std;
int getSum(int val)
{
     int sum = 0;
     while(val > 0)
     {
         sum +=val%10;
         val/=10;
     }
     return sum;
}
bool check(int n,int m,int thre,int nx,int mx,bool *vis)
{
    if(nx>=0 && mx>=0 && nx<n && mx<m && getSum(nx)+getSum(mx)<=thre && !vis[nx*m+mx])
      return true;
    return false;
}
int moveCountCore(int n,int m,int thre,int nx,int mx,bool *vis)
{
    int count = 0;
    if(check(n,m,thre,nx,mx,vis))//判断是否可以进入该格子
    {
        vis[nx*m+mx] = true;
        count = 1+moveCountCore(n,m,thre,nx,mx-1,vis)
        +moveCountCore(n,m,thre,nx,mx+1,vis)
        +moveCountCore(n,m,thre,nx-1,mx,vis)
        +moveCountCore(n,m,thre,nx+1,mx,vis);
    }
    return count;
}
int moveCount(int n,int m,int thre)
{
    if(n<=0||m<=0||thre<=0) return 0;
    bool visited[n*m] = {0};
    return moveCountCore(n,m,thre,0,0,visited);
}
int main()
{
    int n,m,threshold;
    cin>>n>>m>>threshold;
    int count = moveCount(n,m,threshold);
    cout<<count<<endl;
    return 0;
}