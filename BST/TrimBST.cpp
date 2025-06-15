#include"include/TreeNode.h"
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
        void trim(TreeNode* root,int l,int h){
            if(root==NULL) return;
            while(root->left!=NULL) {
                if(root->left->val<l)root->left=root->left->right;
                else if(root->left->val>h)root->left=root->left->left;
                else break;
            }
            
            while(root->right!=NULL) {
                if(root->right->val>h)root->right=root->right->left;
                else if(root->right->val<l)root->right=root->right->right;
                else break;
            }
            trim(root->left,l,h);
            trim(root->right,l,h);
        }
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            TreeNode* temp=new TreeNode(100);
            temp->left=root;
            trim(temp,low,high);
            return temp->left;
        }
    };