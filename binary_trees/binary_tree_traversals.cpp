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

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void preorderIt(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        cout << curr << " ";
        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);
    }
}
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    cout << root->val << " ";
    preorder(root->right);
}
void inorderIt(TreeNode *root)
{
    TreeNode *node = root;
    stack<TreeNode *> st;
    while (!st.empty() || node != NULL)
    {
        if (node)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.size() == 0)
                return;
            TreeNode *temp = st.top();
            st.pop();
            cout << temp->val << " ";
            node = temp->right;
        }
    }
}
void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    preorder(root->right);
    cout << root->val << " ";
}
void postorderIt(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        if (curr->left)
            st.push(curr->left);
        if (curr->right)
            st.push(curr->right);
    }
    reverse(ans.begin(), ans.end());
    for (auto el : ans)
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
    preorder(a);
    cout << endl;
    preorderIt(a);
    cout << endl;
    cout << endl;
    inorder(a);
    cout << endl;
    inorderIt(a);
    cout << endl;
    cout << endl;
    postorder(a);
    cout << endl;
    postorderIt(a);
    return 0;
}