/*@brief:从上到下打印二叉树*/
#include <iostream>
#include <queue>
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
void printTree(BinaryTreeNode* root)
{
    if(root == nullptr) return;
    queue<BinaryTreeNode*> que;
    que.push(root);
    while(que.size())
    {
        BinaryTreeNode* node = que.front();
        cout<<node->val<<" ";
        que.pop();
        if(node->Lchild) que.push(node->Lchild);//注意这里结点的变化
        if(node->Rchild) que.push(node->Rchild);
    }
}
int main()
{
    BinaryTreeNode* root = create();
    printTree(root);
    cout<<endl;
    return 0;
}