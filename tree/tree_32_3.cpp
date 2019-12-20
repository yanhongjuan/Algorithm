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
void printTree(BinaryTreeNode* root)
{
    if(root == nullptr) return;
    int current = 0;//输出的栈
    int nex = 1;//输入的栈
    stack<BinaryTreeNode*> level[2];
    level[current].push(root);
    while(!level[0].empty() || !level[1].empty())
    {
        BinaryTreeNode* node = level[current].top();
        level[current].pop();
        cout<<node->val<<" ";
        if(current == 0)
       {
       if(node->Lchild) level[nex].push(node->Lchild);
       if(node->Rchild) level[nex].push(node->Rchild); 
       }
        else
       {
        if(node->Rchild) level[nex].push(node->Rchild);
        if(node->Lchild) level[nex].push(node->Lchild);
       }
       if(level[current].empty())
       {
          cout<<endl;
          current = 1-current;
          nex = 1-nex;
       }
    }
}
int main()
{
    BinaryTreeNode* root = create();
    printTree(root);
    return 0;
}