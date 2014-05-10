#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
 
 bool isWordBreak(vector<vector<bool> >& words , int i, int j){
 	for (int k = i+1 ; k < j; ++k){
 		if(words[i][k] && words[k][j])
 			return true;
 	}
 	return false;
 }

 bool wordBreak(string s, unordered_set<string> &dict) {
 	int n=s.size();
 	vector<vector<bool> > words(n, vector<bool>(n));     
 	for (int k = 1; k < n; ++k){
 		for (int i = 0; i < n-k; i++){
 			int j=i+k;
 			if( dict.find(s.substr(i,k))!=dict.end()){ // find the word in dictionary
 				words[i][j]=true; 
 				continue;
 			}
 			words[i][j]=isWordBreak(words , i,j);
 		}
 	}
 	return words[0][n-1];  
 }

 int main(int argc, char const *argv[])
 {

 	return 0;
 }