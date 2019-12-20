/*@brief:二叉搜索树的后序遍历序列*/
/*@brief:之字形打印二叉树*/
#include <iostream>
#include <stack>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* Lchild;
    BinaryTreeNode* Rchild;
};
BinaryTreeNode* create()
{
    int k;
    cin>>k;
    if(k == -1) return nullptr;
    else
    {
        BinaryTreeNode* root = new BinaryTreeNode();
        root->val = k;
        root->Lchild = create();
        root->Rchild = create();
        return root;
    }
}
//注意边界值
bool searchTree(int *root,int len)
{
    if(root == nullptr ||len <=0) return false;
    int maxr = root[len-1];
    //二叉搜索树的左子树小于根结点
    int i=0;
    for(;i<len-1;i++)
    {
        if(root[i]>maxr) break;
    }
    //二叉搜索树的右子树大于根结点
    int j = i;
    for(;j<len-1;j++)
    {
        if(root[j] < maxr) return false;
    }
    //判断左子树是否是搜索树
    bool left = true;
    if(i>0) left = searchTree(root,i);
    //判断右右子树是否是搜索树
    bool right = true;
    if(i<len-1) right = searchTree(root+i,len-i-1);
    return left&&right;
}
int main()
{
    int root[] = {7,4,6,5};
    int len = sizeof(root)/sizeof(int);
    bool isPost = searchTree(root,len);
    cout<<isPost<<endl;
    return 0;
}