#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// const int maxn = 100;
struct Node{
    int val;
    Node *left, *right, *parent;
    Node(int val) : left(NULL), right(NULL), parent(NULL), val(val) { }
};



Node* createTree(){
  Node* root=new Node(1);
  //level 2
  root->left=new Node(2);
  root->right=new Node(3);
  //level 3
  root->left->left=new Node(2);
  root->left->right=new Node(2);
  root->right->left=new Node(3);
  return root;
}


vector< vector<int> >  combineTrees(vector<vector<int> >& v1, vector<vector<int> >& v2, vector<vector<int> >& v3 ){
    v1.insert(v1.end(), v2.begin(), v2.end());
    v1.insert(v1.end(), v3.begin(), v3.end());
    return v1;
}


vector<vector<int> > find_all_trees(Node* root){
    vector<vector<int> > v;
    
    if(NULL==root) return v;


    vector<vector<int> > left_all_trees=find_all_trees(root->left);
    vector<vector<int> > right_all_trees=find_all_trees(root->right);


    vector<int> singleV; 
    singleV.push_back(root->val); 
    v.push_back(singleV);

    if(left_all_trees.size()==0 && right_all_trees.size()==0 ){
        return v;
    }




    vector< vector<int>> leftTrees;
    vector< vector<int>> rightTrees;
    vector< vector<int>> crossTrees;

    for (auto& left : left_all_trees ){
        vector<int> leftTree=left;
        leftTree.push_back(root->val);
        leftTrees.push_back(leftTree);
    }

    for (auto& right : right_all_trees){
        vector<int> rightTree=right;
        rightTree.push_back(root->val);
        rightTrees.push_back(rightTree);
    }

    for(auto& left: left_all_trees)
      for (auto& right: right_all_trees) {
          vector<int> crossTree=left;
          crossTree.push_back(root->val);
          for (auto& item : right){
            crossTree.push_back(item);
          }
          crossTrees.push_back(crossTree);
      }

      vector< vector<int> > allTrees= combineTrees(leftTrees, rightTrees, crossTrees);
      allTrees.push_back(singleV);
      return allTrees;
}



int treeSum(const vector<int>& v){
    int sum=0;
    for (auto& item: v){
      sum +=item;
    }
    return sum;
}


vector<vector<int> > find_sum(Node* root, int target){

    vector<vector<int> > pathTrees;  

    if(NULL==root) 
        return pathTrees;

    vector<vector<int> > trees = find_all_trees(root);
    vector<vector<int> > leftSumTrees=find_sum(root->left, target);
    vector<vector<int> > rightSumTrees=find_sum(root->right, target);
  
    for (int i = 0; i < trees.size(); ++i){
        if( treeSum(trees[i]) ==target ){
            pathTrees.push_back(trees[i]);
        }   
    }

    return combineTrees(pathTrees,leftSumTrees, rightSumTrees)  ;
 }



int main(){
    Node* root=createTree();
    vector<vector<int> > v=find_sum(root, 6);
    for (auto& vectorItem : v){
        cout<<" list of item ";
        for (auto& item : vectorItem){
           cout<<item<<" ";
        }
        cout<<endl;
    }

    return 0;
}