class Solution {
public:
    bool hasPathSumReached(TreeNode *root, int currentSum, int sum){
        if(root!=NULL){
            if(root->left==NULL&& root->right==NULL){
                currentSum+=root->val;
                return (currentSum==sum);
            }else{
                currentSum+=root->val;
                return hasPathSumReached(root->left, currentSum, sum)
                    || hasPathSumReached(root->right, currentSum, sum);
            }
        }
        return false;
    }

    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int currentSum=0;
        return hasPathSumReached(root, currentSum, sum);
    }
};