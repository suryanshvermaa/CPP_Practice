#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void display(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}
// sum of all nodes
int sum(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return root->val + sum(root->left) + sum(root->right);
}
// size of binary tree
int size(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
// max treeNode
int maxTreeNode(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;
    return max({root->val, maxTreeNode(root->left), maxTreeNode(root->right)});
}
// levels
int level(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(level(root->left), level(root->right));
}
int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = f;
    display(a);
    cout << endl;
    cout << sum(a) << endl;
    cout << size(a) << endl;
    cout << maxTreeNode(a) << endl;
    cout << level(a) << endl;
    return 0;
}