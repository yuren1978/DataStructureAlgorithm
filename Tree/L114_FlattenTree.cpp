/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flattenTree(TreeNode* root, TreeNode* & head, TreeNode* & tail){
        if(root->left==NULL && root->right==NULL){
            head=root;
            tail=root;
        }
        else{
            head=root;
            TreeNode* leftHead=NULL; TreeNode* leftTail=NULL;
            TreeNode* rightHead=NULL; TreeNode* rightTail=NULL;
            flattenTree(root->left, leftHead, leftTail);
            flattenTree(root->left, rightHead, rightTail);
            head->left=NULL;
            head->right=leftHead;
            leftTail->left=NULL;
            leftTail->right=rightHead;
            tail=rightTail;
        }
    }

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return NULL;
        TreeNode* head=NULL; 
        TreeNode* tail=NULL;
        flattenTree(root, head, tail);
        root=head;
        //return head;
    }
};