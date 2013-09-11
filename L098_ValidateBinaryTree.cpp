
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    bool isBetweenRange(TreeNode* root, int min, int max){
     	if(root==NULL)
 			return true;
 		else{
 			return (root->val>min && root->val<max)
    			&& isBetweenRange(root->left, min, root->val)
    			&& isBetweenRange(root->right, root->val, max);
 		}
 	}

    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max=INT_MAX; int min=INT_MIN;
        return  isBetweenRange(root, min, max);  
    }

int int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}