/*@brief:二叉树的镜像*/
#include <iostream>
using namespace std;
struct BinaryTreeNode 
{
    int val;
    BinaryTreeNode *lchild;
    BinaryTreeNode *rchild;
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
       root->lchild = create();
       root->rchild = create();
       return root;
    }
}
BinaryTreeNode* reverTree(BinaryTreeNode* root)
{
    if(root == nullptr) return nullptr;
    if(root->lchild == nullptr && root->rchild == nullptr) return root;
         BinaryTreeNode* lsave = root->lchild;
         root->lchild = root->rchild;
         root->rchild = lsave;
         if(root->lchild)
         reverTree(root->lchild);
         if(root->rchild)
         reverTree(root->rchild);
         return root; 
}
void printTree(BinaryTreeNode* root)
{
    if(root == nullptr) return;
    cout<<root->val<<" ";
    printTree(root->lchild);
    printTree(root->rchild);
}
int main()
{
   BinaryTreeNode* root = create();
   printTree(root);
   cout<<endl;
   BinaryTreeNode* Vroot = reverTree(root);
   printTree(Vroot);
   cout<<endl;
   return 0;
}