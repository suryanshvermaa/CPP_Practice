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
void leafNodes(TreeNode *root, vector<int> &lN)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        lN.push_back(root->val);
        return;
    }
    leafNodes(root->left, lN);
    leafNodes(root->right, lN);
}

void boundary_traversal(TreeNode *root)
{
    vector<int> lN;
    leafNodes(root, lN);
    vector<int> leftNodes;
    TreeNode *temp = root;
    while (temp->left || temp->right)
    {
        leftNodes.push_back(temp->val);
        if (temp->left)
            temp = temp->left;
        else
            temp = temp->right;
    }
    vector<int> rightNodes;
    temp = root;
    while (temp->left || temp->right)
    {
        rightNodes.push_back(temp->val);
        if (temp->right)
            temp = temp->right;
        else
            temp = temp->right;
    }
    reverse(rightNodes.begin(), rightNodes.end());
    rightNodes.pop_back(); // root two times appearing hence

    // printing
    for (auto el : leftNodes)
    {
        cout << el << " ";
    }
    for (auto el : lN)
    {
        cout << el << " ";
    }
    for (auto el : rightNodes)
    {
        cout << el << " ";
    }
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
    boundary_traversal(a);
    cout << endl;
    return 0;
}