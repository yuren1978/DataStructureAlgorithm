#include <iostream>
#include <string>
#include <vector>


using namespace std;

struct BinaryTree {
  BinaryTree *left, *right;
  int data;
  BinaryTree(int val) : left(NULL), right(NULL), data(val) { }
};


BinaryTree* CreateTreeFromArray(vector<int> array, int start, int end){
	if(start>end){
		return NULL;
	}
	int middle=(start+end)/2;
	BinaryTree* node=new BinaryTree(array[middle]);
	node->left=CreateTreeFromArray(array, start, middle-1);
	node->right=CreateTreeFromArray(array, middle+1, end);
	return node;
}


void serializeHelper(BinaryTree* node, string& s){
        if(node==NULL){
            s += "null";
            return ;
        }
        string currentS=to_string(node->data);
        s += currentS;
        s += ",";
        serializeHelper(node->left, s);
        s += ",";
        serializeHelper(node->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(BinaryTree* root) {
        string s;
        serializeHelper(root, s);
        return s;
    }

  vector<string> split(string data){
        vector<string> words;
        string word;
        int start=0;
        int findPos=data.find(',', start);
        while(findPos!=string::npos){
            word=data.substr(start,findPos-start);
            words.push_back(word);
            start=findPos+1;
            findPos=data.find(',', start);
        } 
        word=data.substr(start);
        words.push_back(word);
        return words;
    }

     BinaryTree* deserializeWords(vector<string>& words, int& index, int size){
       if(index>size || words[index]=="null")
           return NULL;
        BinaryTree* node=new BinaryTree(stoi(words[index]));
        node->left=deserializeWords(words, ++index, size);
        node->right=deserializeWords(words, ++index, size);
        return node;
    }
    

int main(int argc, char *argv[]) {
		vector<int> a = {1, 2, 3} ;
		BinaryTree* root=CreateTreeFromArray(a,0, a.size()-1);
		string rootString= serialize(root);
        cout<<rootString<<endl;

         vector<string> words=split(rootString);
         for(auto word: words){
             cout<<word;
         }
         int index=0;
         BinaryTree* newRoot= deserializeWords(words, index, words.size());
        cout<<endl;
        cout<<newRoot->data;
        cout<<newRoot->left->data;
        cout<<newRoot->right->data;

         return 0;
		//printPretty(root,0,1, cout);
		//int height=maxHeight(root);
		// for (int level=0; level<height; level++) {
		// 	cout<<level<<": ";
		// 	PrintTreeByLevel(root, level);
		// 	cout<<endl;
		// }
		
}