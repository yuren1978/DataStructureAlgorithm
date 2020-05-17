#include <iostream> 
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p){
    if(root==NULL) return NULL;

    inorderPredecessor(root->left, p);    

}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        
        // inorder traversal
        TreeNode* l = inorderSuccessor(root->left, p);
        
        // compare the value of p with the value of current node 
        
        // if p's value is less than current node's value
        if (p->val < root->val) {
            // if calling l on the left subtree of current node returns null
            // then it means that p does not have a right subtree and current 
            // node will be the lowest ancestor whose left subtree contains p
            // in this case, return current node 
            if (l == NULL) 
                return root;
            // otherwise, return the result of inorderSuccessor(root->left, p)
            else 
                return l;
        }
        
        // if p's value is equal to or greater than current node's value 
        // in both case, the successor of p will be potentially in the right subtree 
        // if p does not have a right child, this will eventually return null so that 
        // this will be handled by previous call's above logic
        return inorderSuccessor(root->right, p);
 }


int main(int argc, char const *argv[])
{
    /* code */
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(1);
    root->right=new TreeNode(3);

    TreeNode* inOrderSuccessor=inorderSuccessor(root, root->left);

    cout<<" In order successor " << inOrderSuccessor->val<<endl;

    return 0;
}
