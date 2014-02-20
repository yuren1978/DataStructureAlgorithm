class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
           if(root==NULL) return 0;
        if(root->left==NULL ) return 1+minDepth(root->right);
        if(root ->right==NULL) return 1+minDepth(root->left);
        
        int leftMinDepth=minDepth(root->left)+1;
        int rightMinDepth=minDepth(root->right)+1;
        return leftMinDepth<rightMinDepth ? leftMinDepth:rightMinDepth;
    }
};