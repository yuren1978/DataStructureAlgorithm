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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        stack<TreeNode*> stack;
        TreeNode* current=root;
        while(current!=NULL || stack.size()>0) {
            if(current!=NULL){
                stack.push(current);
                current=current->left;
            }
            else{
                current=stack.top();
                if(current!=NULL) v.push_back(current->val);
                stack.pop();
                current=current->right;
            }
        }
        return v;
    }
};