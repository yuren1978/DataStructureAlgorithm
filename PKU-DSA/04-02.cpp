#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      char val;
      int level;
      TreeNode *left;
      TreeNode *right;
      TreeNode *parent;
      TreeNode(char x, int level) : val(x), level(level), left(NULL), right(NULL), parent(NULL){}
};

void preVisit(const TreeNode* root){
   if(root!=NULL){
      cout<<root->val;
      preVisit(root->left);
      preVisit(root->right);
   }
}

void postVisit(const TreeNode* root){
  if(root!=NULL){
    postVisit(root->left);
    postVisit(root->right);
    cout<<root->val;
  }
}

void inVisit(const TreeNode* root){
  if(root!=NULL){
    inVisit(root->left);
    cout<<root->val;
    inVisit(root->right);
    
  }
}

TreeNode* findParent(TreeNode* currentNode, int level){
   while(currentNode->level!=level){
      currentNode=currentNode->parent;
   }
   return currentNode;
}

TreeNode* processCase(){
  string currentLine;
  TreeNode* root=NULL;
  TreeNode* prevNode=NULL;
  while (std::getline(std::cin >> std::ws, currentLine) && currentLine!="0"){
      //process this line
      int count=0;
      while(currentLine[count]=='-'){
        count++;
      }
      char currentChar=currentLine[count];

      //cout<<currentChar<<" "<<count<<endl;
        TreeNode* newNode=new TreeNode(currentChar, count);
        if(count==0){
            root=newNode;
            prevNode=newNode; 
        }
        else{
            if(count>prevNode->level){//set left
              if(newNode->val!='*')
                prevNode->left=newNode;
              else
                prevNode->left=NULL;
              newNode->parent=prevNode;
            }
            else if(count==prevNode->level){//set right
                if(newNode->val!='*')
                  prevNode->parent->right=newNode;
                else
                  prevNode->parent->right=NULL;
                newNode->parent=prevNode->parent;
            }
            else{//set right.
                TreeNode* currentParent=findParent(prevNode,  count-1);
                currentParent->right=newNode;
                newNode->parent=currentParent;
            }
            prevNode=newNode;
        }
     
  }
  return root;
}

int  main()
{
    int n;
    cin >> n;
    while(n>0){
      TreeNode* root= processCase();
      preVisit(root); 
      cout<<endl;
      postVisit(root);
      cout<<endl;
      inVisit(root);
      cout<<endl;
      n--;
      if(n>0)
        cout<<endl;
    }
    return 0;
}