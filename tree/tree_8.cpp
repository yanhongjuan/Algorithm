/*@brief:求二叉树中序遍历的下一个结点*/
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* lchild;
    BinaryTreeNode* rchild;
    BinaryTreeNode* tparent;
};
BinaryTreeNode* createBinaryTreeNode(int value)
{
    BinaryTreeNode* node = new BinaryTreeNode();
    node->val = value;
    node->lchild = nullptr;
    node->rchild = nullptr;
    node->tparent = nullptr;
    return node;
}
void connectTreeNode(BinaryTreeNode* pParent,BinaryTreeNode* plchild,BinaryTreeNode* prchild)
{
    if(pParent != nullptr)
    {
        pParent->lchild = plchild;
        pParent->rchild = prchild;
        if(plchild != nullptr) plchild->tparent = pParent;
        if(prchild != nullptr) prchild->tparent = pParent;
    }
}
BinaryTreeNode* GetNext(BinaryTreeNode* node)
{
    if(node == nullptr) return nullptr;
    BinaryTreeNode* pNext = nullptr;
     if(node->rchild != nullptr)//该结点有右子树,那么它的下一个节点就是它的右子树的最左子结点
     {
        BinaryTreeNode* rnext = node->rchild;
        while(rnext->lchild != nullptr)
        {
            rnext = rnext->lchild;
        }
        pNext = rnext;
     }
     else
     {
        //该结点没有右子树,则它的下一个结点为它是父节点的左结点的那个结点
        if(node->tparent != nullptr)
        {
            BinaryTreeNode* pCurrent = node;
            BinaryTreeNode* pParent = pCurrent->tparent;
            while(pParent != nullptr && pCurrent == pParent->rchild)
            {
                pCurrent = pParent;
                pParent =  pCurrent->tparent;
            }
            pNext = pParent;
        }
     }
     return pNext;
}
void test1()
{
    BinaryTreeNode* node8 = createBinaryTreeNode(8);
    BinaryTreeNode* node6 = createBinaryTreeNode(6);
    BinaryTreeNode* node10 = createBinaryTreeNode(10);
    BinaryTreeNode* node5 = createBinaryTreeNode(5);
    BinaryTreeNode* node7 = createBinaryTreeNode(7);
    BinaryTreeNode* node9 = createBinaryTreeNode(9);
    BinaryTreeNode* node11 = createBinaryTreeNode(11);
    connectTreeNode(node8,node6,node10);
    connectTreeNode(node6,node5,node7);
    connectTreeNode(node10,node9,node11);
    BinaryTreeNode* pnext = GetNext(node5);
    cout<<pnext->val<<endl;
}
int main()
{
   test1();
   return 0;
}