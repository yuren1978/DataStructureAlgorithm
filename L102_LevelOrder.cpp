class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > levelOrderVector;
        if(root==NULL){
        	return levelOrderVector;
        }
        else{
        	queue<pair<int,TreeNode*>> levelQueue;
        	levelQueue.push_back(make_pair(0,root));
        	int currentLevel=0;
        	vector<int> currentVector;
        	while(!levelQueue.empty()){
        		pair<int,TreeNode*> current=levelQueue.front();
        		levelQueue.pop();
        		if(current.first==currentLevel){
        			currentVector.push_back(current.second->val);
        		}
        		else{
        			currentLevel=current.first;
        			levelOrderVector.push_back(currentVector);
        			currentVector.clear();
        			currentVector.push_back(current.second->val);
        		}
        		if(current.second->left!=NULL)
        			levelQueue.push_back(make_pair(current.first+1,current.second->left) );
        		if(current.second->right!=NULL)
        			levelQueue.push_back(make_pair(current.first+1,current.second->right) );
        	}
        }
    }
};