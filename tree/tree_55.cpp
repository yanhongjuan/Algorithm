/*@brief:求二叉树的深度*/
#include <iostream>
using namespace std;
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
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
        root->left = create();
        root->right = create();
        return root;
    }
}
int DepthTree(BinaryTreeNode *root)
{
    if(root == nullptr) return 0;
    int left = DepthTree(root->left);//求左子树的深度
    int right = DepthTree(root->right);//求右子树的深度
    return (left>right)?(left+1):(right+1);//求得子树深度后加1即为根的深度
}
int main()
{
    BinaryTreeNode* root = create();
    int n = DepthTree(root);
    cout<<n<<endl;
    return 0;
}