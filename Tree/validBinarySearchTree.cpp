     #include <iostream>
    #include <stack>

     using namespace std;   

    struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };


  bool isValidBST(TreeNode *root) {
        //do an in-order travel
        if(NULL==root)
            return true;
        TreeNode* prev=NULL;        
        stack<TreeNode*> s;
        TreeNode* current=root;
        while(current || !s.empty()){
            if(current){
                s.push(current);
                current=current->left;
            }
            else{
                current=s.top();
                cout<<"current val "<<current->val<<endl;

                if(prev!=NULL && prev->val>=current->val){
                    cout<<"return false"<<endl;
                    return false;
                }
                  cout<<"current val "<<current->val<<endl;
                prev=current;
                s.pop();
                current=current->right;
            }
        }
        cout<<"return ture";
        return true;
    }

    int main(int argc, char const *argv[])
    {
        
        TreeNode* root=new TreeNode(5);

        cout<<isValidBST(root)<<endl;
    }