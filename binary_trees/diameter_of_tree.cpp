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
int level(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(level(root->left), level(root->right));
}
int diameter_of_tree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return max({level(root->left) + level(root->right), diameter_of_tree(root->left), diameter_of_tree(root->right)});
}
// is the same tree
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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

    cout << diameter_of_tree(a) << endl;
    return 0;
}
// lowest common ancestor
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    bool search(TreeNode *root, int x)
    {
        if (root == NULL)
            return false;
        if (root->val == x)
            return true;
        return search(root->left, x) || search(root->right, x);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;
        else if ((search(root->left, p->val) && search(root->right, q->val)) || (search(root->left, q->val) && search(root->right, p->val)))
            return root;
        else if (search(root->left, p->val))
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};