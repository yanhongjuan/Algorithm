/*@brief:对称的二叉树*/
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *Lchild;
    BinaryTreeNode *Rchild;
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
bool isSym(BinaryTreeNode* root1,BinaryTreeNode *root2)
{
    if(root1 == nullptr && root2 == nullptr) return true;
    if(root1==nullptr || root2==nullptr) return false;
    if(root1->val != root2->val) return false;
    return isSym(root1->Lchild,root2->Rchild)&&isSym(root1->Rchild,root2->Lchild);
}
bool isSym(BinaryTreeNode* root)
{
    return isSym(root,root);
}
int main()
{
    BinaryTreeNode* root = create();
    bool res = false;
    res = isSym(root);
    cout<<res<<endl;
    return 0;
}