#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      int leftVal;
      int rightVal;
      TreeNode* parent;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x,int leftx,int rightx) : val(x), leftVal(leftx), rightVal(rightx) ,left(NULL), right(NULL), parent(NULL) {}
};

TreeNode* findNode(TreeNode* root, int num){
    if(NULL==root) return NULL;
    if(root->val==num) return root;
    TreeNode* leftResult=findNode(root->left, num);
    if(leftResult!=NULL) return leftResult;
    TreeNode* rightResult= findNode(root->right, num);
    if(rightResult!=NULL) return rightResult;
}


TreeNode* findNodeInArray(const vector<TreeNode*>& nodeArray, int currentValue){
    int size=nodeArray.size();
    for (int i = 0; i < size; ++i){
       if(currentValue==nodeArray[i]->val){
          return nodeArray[i];
       }
    }
    return NULL;
}



TreeNode*  buildTree(const vector<TreeNode*>& nodeArray, int currentValue){
    TreeNode* currentNode=findNodeInArray(nodeArray, currentValue);
    if(currentNode!=NULL && currentNode->leftVal!=-1){
        TreeNode* leftNode=buildTree(nodeArray, currentNode->leftVal);
        currentNode->left=leftNode;
        leftNode->parent=currentNode;
    }
    if(currentNode!=NULL && currentNode->rightVal!=-1){
         TreeNode* rightNode=buildTree(nodeArray, currentNode->rightVal);
         currentNode->right=rightNode;
         rightNode->parent=currentNode;
    }
    return currentNode;

}

void processCase(){
  
  int n, m;
  cin>>n>>m;
  //cout<<"output"<<n<<" "<<m<<endl;
  vector<TreeNode*> nodeArray;
  while(n>0){
    int num, left, right;
    cin>>num>>left>>right;
    nodeArray.push_back(new TreeNode(num, left, right));
    n--;
  }

  TreeNode* root=buildTree(nodeArray, 0);


  while(m>0){
     int type;
     cin>>type;
     if(1==type){
        int x,y;
        cin>>x>>y;
        //do exchange.
        TreeNode* xNode=findNode(root, x);
        TreeNode* yNode=findNode(root, y);

           TreeNode* temp=xNode;

          TreeNode* xParent=xNode->parent;
          bool xLeft=(xParent->left==xNode);

          TreeNode* yParent=yNode->parent;
          bool yLeft=(yParent->left==yNode);

          if(xLeft)
            xParent->left=yNode;
          else
            xParent->right=yNode;

          yNode->parent=xParent;

          if(yLeft)
            yParent->left=temp;
          else
            yParent->right=temp;

          temp->parent=yParent;
        

     }
     else if(2==type){
        int x;
        cin>>x;
        //print left child
        TreeNode* node=findNode(root, x);
        if(node!=NULL){
          while(node->left!=NULL){
            node=node->left;
          }
          cout<<node->val<<endl;          
        }
     }
     m--;
  }
}

int  main()
{
    int n;
    cin >> n;
    while(n>0){
      processCase();
      n--;
    }
    return 0;
}