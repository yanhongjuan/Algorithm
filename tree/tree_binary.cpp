/*@brief:二叉树最简单的遍历*/
#include <iostream>
using namespace std;
template <typename T>
class binaryTreeNode
{
public:
    int element;
    binaryTreeNode* lchild;
    binaryTreeNode* rchild;
    binaryTreeNode()
    {
        lchild = nullptr;
        rchild = nullptr;
    }
};
template <typename T>
class binaryTree
{
    public:
    binaryTreeNode<T>* create();
    void preTree(binaryTreeNode<T>*);
    void proTree(binaryTreeNode<T>*);
    void midTree(binaryTreeNode<T>*);
};
//前序构建二叉树
template <typename T>
binaryTreeNode<T>* binaryTree<T>::create()
{
    binaryTreeNode<T>* current = nullptr;
    T val;
    cin>>val;
    if(val == -1) return nullptr;
    else
    {
        current = new binaryTreeNode<T>();
        current->element = val;
        current->lchild = create();
        current->rchild = create();
        return current;
    }
}
//前序遍历
template <typename T>
void binaryTree<T>::preTree(binaryTreeNode<T>* current)
{
    if(current == nullptr) return;
    cout<<current->element<<" ";
    preTree(current->lchild);
    preTree(current->rchild);
}
//后序遍历
template <typename T>
void binaryTree<T>::proTree(binaryTreeNode<T>* current)
{
    if(current == nullptr) return;
    proTree(current->lchild);
    proTree(current->rchild);
    cout<<current->element<<" ";
}
//中序遍历
template <typename T>
void binaryTree<T>::midTree(binaryTreeNode<T>* current)
{
    if(current == nullptr) return;
    midTree(current->lchild);
    cout<<current->element<<" ";
    midTree(current->rchild);
}
int main()
{
    binaryTreeNode<int>* current;
    binaryTree<int> bt;
    current = bt.create();
    bt.preTree(current);
    cout<<endl;
    bt.proTree(current);
    cout<<endl;
    bt.midTree(current);
    cout<<endl;
    return 0;
}