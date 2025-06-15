#include<bits/stdc++.h>
#include"include/TreeNode.h"
using namespace std;
void printTree(TreeNode* root){
    queue<TreeNode*> qu;
    qu.push(root);
    while(!qu.empty()){
        int s=qu.size();
        for(int i=0;i<s;i++){
            auto curr=qu.front();
            qu.pop();
            cout<<curr->val<<" ";
            if(curr->left) qu.push(curr->left);
            if(curr->right) qu.push(curr->right);
        }
        cout<<endl;
    }
}

//delete a node having Zero child
TreeNode* deleteNodeWith0Child(TreeNode* root,int x){
    if(root==NULL) return NULL;
    if(root->val==x) return NULL;
    root->left=deleteNodeWith0Child(root->left,x);
    root->right=deleteNodeWith0Child(root->right,x);
    return root;
}

//delete a node having One child
TreeNode* deleteNodeWith1Child(TreeNode* root,int x){
    if(root==NULL) return NULL;
    if(root->val==x) return root->left?root->left:root->right;
    root->left=deleteNodeWith1Child(root->left,x);
    root->right=deleteNodeWith1Child(root->right,x);
    return root;
}

//delete a node having Two child
TreeNode* deleteNodeWith2Child(TreeNode* root,int x){
    if(root==NULL) return NULL;
    if(root->val==x){
        //find inorder precessar
        TreeNode* pred=root;
        pred=pred->left;
        while(pred->right){
            pred=pred->right;
        }
        deleteNodeWith0Child(root,pred->val);
        root->val=pred->val;
        return root;
    }
    root->left=deleteNodeWith2Child(root->left,x);
    root->right=deleteNodeWith2Child(root->right,x);
    return root;
}

int main(){
    //BST
    TreeNode* a=new TreeNode(3);
    TreeNode* b=new TreeNode(1);
    TreeNode* c=new TreeNode(5);
    TreeNode* d=new TreeNode(0);
    TreeNode* e=new TreeNode(2);
    TreeNode* f=new TreeNode(4);
    TreeNode* g=new TreeNode(6);
    TreeNode* h=new TreeNode(8);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    g->left=h;
    printTree(a);
    a=deleteNodeWith2Child(a,3);
    cout<<"-------------------\n";
    printTree(a);
    return 0;
}