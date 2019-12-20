/*@brief:判断是否是树的子结构*/
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* Lchild;
    BinaryTreeNode* Rchild;
};
/*BinaryTreeNode* createBinaryTreeNode(int value)
{
    BinaryTreeNode* node = new BinaryTreeNode();
    node->val = value;
    node->Lchild = nullptr;
    node->Rchild = nullptr;
    node->tparent = nullptr;
    return node;
}
void connectTreeNode(BinaryTreeNode* pParent,BinaryTreeNode* plchild,BinaryTreeNode* prchild)
{
    if(pParent != nullptr)
    {
        pParent->Lchild = plchild;
        pParent->Rchild = prchild;
        if(plchild != nullptr) plchild->tparent = pParent;
        if(prchild != nullptr) prchild->tparent = pParent;
    }
}*/
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
bool DoseTree1HaveTree2(BinaryTreeNode* root1,BinaryTreeNode* root2)
{
    if(root2 == nullptr) return true;
    if(root1 == nullptr) return false;
    if(root1->val != root2->val) return false;
    return (DoseTree1HaveTree2(root1->Lchild,root2->Lchild) && DoseTree1HaveTree2(root1->Rchild,root2->Rchild));
}
bool SubTree(BinaryTreeNode* root1,BinaryTreeNode* root2)
{
    bool result = false;
    if(root1 != nullptr && root2 != nullptr)//如果根结点相同,就判断A中是否含有B,否则遍历A树
    {
        if(root1->val == root2->val) 
          result = DoseTree1HaveTree2(root1,root2);
        if(!result)
          result = SubTree(root1->Lchild,root2);
        if(!result)
          result = SubTree(root1->Rchild,root2);
    }
    return result;
}
int main()
{
   /* BinaryTreeNode* node8 = createBinaryTreeNode(8);
    BinaryTreeNode* node6 = createBinaryTreeNode(6);
    BinaryTreeNode* node10 = createBinaryTreeNode(10);
    BinaryTreeNode* node5 = createBinaryTreeNode(5);
    BinaryTreeNode* node7 = createBinaryTreeNode(7);
    BinaryTreeNode* node9 = createBinaryTreeNode(9);
    BinaryTreeNode* node11 = createBinaryTreeNode(11);
    connectTreeNode(node8,node6,node10);
    connectTreeNode(node6,node5,node7);
    connectTreeNode(node10,node9,node11);
    BinaryTreeNode* node28 = createBinaryTreeNode(6);
    BinaryTreeNode* node26 = createBinaryTreeNode(5);
    BinaryTreeNode* node210 = createBinaryTreeNode(2);
    connectTreeNode(node28,node26,node210);*/
    BinaryTreeNode* p1 = create();
    BinaryTreeNode* p2 = create();
    bool res = SubTree(p1,p2);
    cout<<res<<endl;
    return 0;
}