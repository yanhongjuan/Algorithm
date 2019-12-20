/*@brief:将二叉搜索树转换成一个排序的双向链表*/
#include <iostream>
using namespace std;
template <typename T>
class binaryTreeNode
{
    public:
       int element;
       binaryTreeNode *lchild;
       binaryTreeNode *rchild;
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
    binaryTreeNode<T> *create();
};
//前序遍历构建二叉树
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
template <typename T>
binaryTreeNode<T>* convert(binaryTreeNode<T> *pRootOfTree)
{
    binaryTreeNode<T> *pLastNodeInList = nullptr;//指向双向链表的尾节点
    convertNode(pRootOfTree,&pLastNodeInList);
    binaryTreeNode<T> *pHeadOfList = pLastNodeInList;//需要返回头节点
    while(pHeadOfList != nullptr && pHeadOfList->lchild != nullptr)
       pHeadOfList = pHeadOfList->lchild;
    return pHeadOfList;
}
template <typename T>
void convertNode(binaryTreeNode<T>* pNode,binaryTreeNode<T>* &pLastNodeInList)
{
    if(pNode == nullptr) return;
    binaryTreeNode<T> *pCurrent = pNode;
    if(pCurrent->lchild != nullptr) convertNode(pCurrent->lchild,pLastNodeInList);
    pCurrent->lchild = pLastNodeInList;
    if(pLastNodeInList != nullptr) pLastNodeInList->rchild = pCurrent;
    pLastNodeInList = pCurrent;
    if(pCurrent->rchild != nullptr)
    convertNode(pCurrent->rchild,pLastNodeInList);
}