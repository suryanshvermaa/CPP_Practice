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

TreeNode *construct(vector<int> &arr)
{
    int n = arr.size();
    queue<TreeNode *> qu;
    TreeNode *root = new TreeNode(arr[0]);
    qu.push(root);
    int i = 1;
    while (!qu.empty() && i < arr.size())
    {
        TreeNode *curr = qu.front();
        qu.pop();
        if (arr[i] != -1)
        {
            TreeNode *temp = new TreeNode(arr[i]);
            curr->left = temp;
            qu.push(temp);
        }
        i++;
        if (i < arr.size() && arr[i] != -1)
        {
            TreeNode *temp = new TreeNode(arr[i]);
            curr->right = temp;
            qu.push(temp);
        }
        i++;
    }
    return root;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8, 9, -1};
    TreeNode *root = construct(arr);
    display(root);
    cout << endl;
    return 0;
}