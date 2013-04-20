class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &num, int start, int end){
        if(start>end){
            return NULL;
        }
        if(start==end){
            return new TreeNode(num[start]);
        }
        else{
            int middle=(start+end)/2;
            TreeNode* treeNode=new TreeNode(num[middle]);
            treeNode->left=sortedArrayToBST(num, start, middle-1);
            treeNode->right=sortedArrayToBST(num, middle+1, end);
            return treeNode;
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=num.size();
        if(size==0) return NULL;
        if(size==1) return new TreeNode(num[0]);
        return sortedArrayToBST(num, 0, size-1);
    }
};