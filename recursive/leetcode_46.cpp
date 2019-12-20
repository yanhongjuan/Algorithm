/*@brief:全排列*/
//力扣46
#include <iostream>
#include <vector>
using namespace std;
int n;
void dfs(vector<int>& nums,int level,vector<bool>& visited,vector<int>& tmp,vector<vector<int>>& results)
{
	//每次搜索的结束条件
     if(level == n)//level表示生成排列的第n个位置
	 results.push_back(tmp);
     else
	 {
		 for(int i=0;i<n;i++)//表示第i个位置的值
		 {
			 if(visited[i]==0)
			 {
                 visited[i] = 1;//被访问标记
				 tmp.push_back(nums[i]);
				 dfs(nums,level+1,visited,tmp,results);//以level+1为根进行遍历
				 tmp.pop_back();
				 visited[i] = 0;//进行回溯,我们自己设置的变量记得退回,虽然递归的回溯是自动进行的
			 }
		 }
	 } 
}
int main()
{
	int k,m;
	vector<int> nums;//需要全排列的元素
	vector<vector<int>> results;//存储最后所有全排列的结果
    vector<int> tmp;//存储每一次排列组合的结果
	vector<bool> visited(nums.size(),false);//存储每个值是否被访问，即有存储位置
	while(cin>>k)
	{
		nums.push_back(k);
		if(cin.get()=='\n')
		    break;
	}
	n = nums.size();
	dfs(nums,0,visited,tmp,results);//以第一个位置0为根开始深度遍历
	m = results.size();
	for(int i=0;i<m;i++)
	{
	  for(int j=0;j<n;j++)
	  {
		  cout<<results[i][j]<<" ";
	  }
	  cout<<endl;
	}
	return 0;
}
