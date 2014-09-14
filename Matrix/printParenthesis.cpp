#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


struct info_pair {
	int left;
	int right;
	string s;
	info_pair(string st,int l, int r):left(l),right(r), s(st){}
};

vector<string> generateParenthesis(int n){
	vector<string> v;
	queue<info_pair> q;

	q.push(info_pair("",0,0));

	while(!q.empty()){
		auto current=q.front();
		q.pop();
		if(current.left==n && current.right==n){
			v.push_back(current.s);
		}
		else{
			if(current.left<n){
				q.push(info_pair(current.s+"(", current.left+1,current.right));
			}

			if(current.left>current.right){
				q.push(info_pair(current.s+")", current.left,current.right+1));	
			}
		}

	}

	return v;
}

int main(int argc, char const *argv[])
{
	vector<string> v=generateParenthesis(3);
	for (auto& s: v){
		cout<<s<<endl;
	}
	return 0;
}