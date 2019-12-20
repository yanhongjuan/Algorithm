/*@brief:重建二叉树,输入前序遍历和中序遍历的结果*/
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *lchild;
    BinaryTreeNode *rchild;
};
BinaryTreeNode* ConstructCore(int *startpreorder,int *endpreorder,int *startinorder,int *endinorder)
{
    int rootpre = startpreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->val = rootpre;
    root->lchild = nullptr;
    root->rchild = nullptr;
   /* if(startpreorder == endpreorder)
    {
        if(startinorder == endinorder && *startpreorder == *startinorder) return root;
    }*/
    int *rootinorder = startinorder; 
    while(rootinorder <= endinorder && *rootinorder != rootpre)
    {
        ++rootinorder;//找到中序遍历中的根结点位置
    }
    int len = rootinorder - startinorder;//求得左子树的长度
    int *leftpreorderend = startpreorder+len;
    if(len > 0)
        root->lchild = ConstructCore(startpreorder+1,leftpreorderend,startinorder,rootinorder-1);
    if(len < endpreorder-startpreorder)
        root->rchild = ConstructCore(leftpreorderend+1,endpreorder,rootinorder+1,endinorder);
    return root;
}
BinaryTreeNode* Construct(int *preorder,int *inorder,int len)
{
    if(preorder == nullptr || inorder == nullptr || len <= 0)
        return nullptr;
    return ConstructCore(preorder,preorder+len-1,inorder,inorder+len-1);
}
void printtree(BinaryTreeNode* res)
{
    if(res != nullptr)
    {
        cout<<res->val<<endl;
        if(res->lchild != nullptr) printtree(res->lchild);
        if(res->rchild != nullptr) printtree(res->rchild);
    }
}
void test1()
{
    const int length = 8;
    int preorder[length] = {1,2,4,7,3,5,6,8};
    int inorder[length] = {4,7,2,1,5,3,8,6};
    BinaryTreeNode* res = Construct(preorder,inorder,length);
    printtree(res);
    cout<<endl;
}
int main()
{
  test1();
}