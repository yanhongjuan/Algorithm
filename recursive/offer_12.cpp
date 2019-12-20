/*@brief:矩阵中的路径*/
#include <iostream>
using namespace std;
bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int pathLen,bool* visited)
{
    if(str[pathLen]=='\0') return true;//结束条件
    bool haspath = false;
    if(row >=0 && row < rows && col < cols && matrix[row*cols+col] == str[pathLen] && !visited[row*cols+col])
    {
        ++pathLen;
        visited[row*cols+col] = true;
        haspath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLen,visited)
        ||hasPathCore(matrix,rows,cols,row-1,col,str,pathLen,visited)
        ||hasPathCore(matrix,rows,cols,row,col+1,str,pathLen,visited)
        ||hasPathCore(matrix,rows,cols,row+1,col,str,pathLen,visited);
        if(!haspath)
        {
            --pathLen;
            visited[row*cols+col] = false;
        } 
    }
    return haspath;
}
bool hasPath(const char* matrix,int rows,int cols,const char* str)
{
    if(matrix == nullptr || rows<1 || cols<1 || str == nullptr) return false;
    bool visited[rows*cols] = {0};
    int pathLen = 0;
    for(int row = 0;row < rows;row++)
       for(int col = 0;col < cols;col++)
       {
           if(hasPathCore(matrix,rows,cols,row,col,str,pathLen,visited))//一个位置一个位置遍历
              return true;
       }
    return false;
}
int main()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
    bool isExit = hasPath(matrix,3,4,str);
    cout<<isExit<<endl;
    return 0;
}