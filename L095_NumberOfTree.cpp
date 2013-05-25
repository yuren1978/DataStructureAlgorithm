#include <iostream>
#include <vector>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
  vector<TreeNode *> generateTreeFromStartToEnd( int start, int end){
        vector<TreeNode *> v;
        
        if(start>end) { vector<TreeNode *> v; v.push_back(NULL) ; return v;  }
        if(end-start==0) { vector<TreeNode *> v; v.push_back(new TreeNode(start)); return v; }
        if(end-start==1) {
            vector<TreeNode *> v;
            TreeNode* root1=new TreeNode(start); root1->right=new TreeNode(end);
            v.push_back(root1);
            TreeNode* root2=new TreeNode(end); root2->left=new TreeNode(start);
            v.push_back(root2);
            return v;
        }
        
        for(int i=start; i<=end; i++){
            
            vector<TreeNode*> leftTrees=generateTreeFromStartToEnd(start, i-1);
            vector<TreeNode*> rightTrees=generateTreeFromStartToEnd( i+1, end );
            
            for(int li=0; li<leftTrees.size(); li++){
                for(int ri=0; ri<rightTrees.size(); ri++){
                    TreeNode* root=new TreeNode(i);
                    root->left=leftTrees[li];                    
                    root->right=rightTrees[ri];
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return  generateTreeFromStartToEnd(1, n);
      
    }