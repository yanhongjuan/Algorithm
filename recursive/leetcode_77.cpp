/*@brief:组合问题*/
#include<iostream>
#include <vector>
using namespace std;
int n,r;
vector<vector<int>> results;

void dfs(int n,int r,int x,vector<int>& vec) //代表r中的第k个位置
{
	if(vec.size() == r)
	{
		results.push_back(vec);
		return;
	}
	for (int i=x; i<=n; ++i)
	{
         vec.push_back(i);//这里不需要设置标志位,是因为它是从下一位开始的i+1
		 dfs(n,r,i+1,vec);
		 vec.pop_back();
	}
}
 
int main() {
	cin >> n >> r;//从n个数中取r个数进行组合
	vector<int> vec;
	dfs(n,r,1,vec);//从取第1个数开始
	for(int i=0;i<(int)results.size();i++)
	{
		for(int j=0;j<r;j++)
		{
            cout<<results[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}



