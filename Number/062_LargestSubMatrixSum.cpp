//https://docs.google.com/spreadsheet/pub?key=0AqHq2JLBVNBwdHJkVEFuRWExT2owWGNKOXM4WnpQZEE&single=true&gid=0&output=html
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <queue>

using namespace std;

	struct TreeNode{
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x): val(x), left(NULL),right(NULL){}
	};

	template<typename Out>
	void split(const std::string &s, char delim, Out result) {
	    std::stringstream ss(s);
	    std::string item;
	    while (std::getline(ss, item, delim)) {
	        *(result++) = item;
	    }
	}

	std::vector<std::string> split(const std::string &s, char delim) {
	    std::vector<std::string> elems;
	    split(s, delim, std::back_inserter(elems));
	    return elems;
	}
	
    void serializeTree(TreeNode* root, string& serializeString, int treeHeight){
        queue<pair<TreeNode*,int> > travelQueue;
        travelQueue.push(make_pair(root, 1) );
        while(!travelQueue.empty()){
            TreeNode* front=travelQueue.front().first;
            int height=travelQueue.front().second;
            
            if(front==NULL ){
                if(height<=treeHeight){
                    serializeString += ",";
                     serializeString += "null";
                }      
            }
            else{
                if(height>1)
                    serializeString += ",";
                serializeString += to_string(front->val);
                travelQueue.push(make_pair(front->left,height+1) );
                travelQueue.push(make_pair(front->right,height+1));
            }
            travelQueue.pop();
        }
    };

    int getHeightOfTree(TreeNode* root, int height){
        if(root==NULL) return height;
        int left=getHeightOfTree(root->left, height+1);
        int right=getHeightOfTree(root->right, height+1);
        return max(left,right);
    }
    
    string serialize(TreeNode* root) {
        int treeHeight= getHeightOfTree(root, 0);
        string serializeString;
        serializeString +="[";
        serializeTree(root, serializeString, treeHeight);
        serializeString +="]";
        cout<<serializeString<<endl;
        return serializeString;
    }
    
    // Encodes a tree to a single string.
    void deserialize(TreeNode* current, const  vector<string>& dataVector, int index, int size){
        if(dataVector[index]=="null" || index>=size ){
            current=NULL;
            return;
        }
        current=new TreeNode(std::stoi(dataVector[index]));
        deserialize(current->left, dataVector, 2*index+1, size);
        deserialize(current->right, dataVector, 2*index+2, size);   
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	int size=data.length();
        vector<string> dataVector=split(data.substr(1,size-2),',');
        if(dataVector.size()==0)
            return NULL;
        TreeNode* root;
        int index=0;
        deserialize(root,  dataVector, index, dataVector.size());
        return root;
    }
	

	int main(int argc, char *argv[]) {
		TreeNode* root=new TreeNode(1);
		root->left=new TreeNode(2);
		root->right=new TreeNode(3);
		string serizeString=serialize(root);
		cout<<serizeString<<endl;
		TreeNode* deserializeRoot=deserialize(serizeString);
		cout<<deserializeRoot->val<<endl;
	}