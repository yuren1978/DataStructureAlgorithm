class Solution {
public:
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        return leftDepth>rightDepth?(1+leftDepth):(1+rightDepth);
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return true;
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        return isBalanced(root->left) && isBalanced(root->right) && (leftDepth-rightDepth>=-1 && leftDepth-rightDepth<=1);
        
    }
};