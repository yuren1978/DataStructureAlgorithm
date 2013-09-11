class Solution {
public:
    void sumNumbersRecursively(TreeNode *root, int sumOnCurrentPath, int& sum){
        
        if(root->left==NULL && root->right == NULL){
            sumOnCurrentPath=10*sumOnCurrentPath+root->val;
            sum+=sumOnCurrentPath;
            return;
        }
        if(root->left!=NULL){
            sumNumbersRecursively(root->left, 10*sumOnCurrentPath+(root->val), sum );
        }
            
        
        if(root->right!=NULL){
            sumNumbersRecursively(root->right, 10*sumOnCurrentPath+(root->val), sum );
        }
    }
            


    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        int sum=0;
        int sumOnCurrentPath=0;
        sumNumbersRecursively(root,sumOnCurrentPath,  sum);
        return sum;
    }
};