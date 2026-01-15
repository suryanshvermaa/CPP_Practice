/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,int i1,int j1,int i2,int j2){
        if(i1>j1||i2>j2) return NULL;
        int dist=0;
        int i=i2;
        while(i<=j2&&inorder[i]!=preorder[i1]){
            dist++;
            i++;
        }
        TreeNode* root=new TreeNode(preorder[i1]);
        root->left=f(preorder,inorder,i1+1,i1+dist,i2,i-1);
        root->right=f(preorder,inorder,i1+dist+1,j1,i+1,j2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};