#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <string>
#include <unordered_set>

using namespace std;

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size()+1;
    	vector< vector< vector<int> > > dp(n, vector< vector<int> >() );
    
    	for (int i = 1; i <= s.size(); ++i){
    		for (int j = 0; j < i; ++j){
    			if((j==0 || dp[j].size()>0) && dict.find(s.substr(j, i-j))!=dict.end()){
    				if(j==0){
    				    vector<int> v{j,i}; 
    				    dp[i].push_back(v);
    				}
    				else{
    				    for(auto& vj:dp[j]){
    				        vj.push_back(i);
    				        dp[i].push_back(vj);
    				    }
    				}
    			}
    		}	
    	}

        cout<<"break "<<endl;
    	
    	set<string> resultset;
        for(auto& v : dp[n-1]){
            string cs;
            for(size_t i=0; i<=v.size()-1; i++){
                cs+=s.substr(v[i], v[i+1]-v[i]);
                if(i!=v.size()-1)
                    cs+=" ";
            }
            resultset.insert(cs);
        }
        vector<string>  results(resultset.begin(),resultset.end());
        return results;
    }

int main(int argc, char const *argv[])
{
    //string s="catsanddog";
    //unordered_set<string> dic{"cat", "cats", "and", "sand", "dog"};
    string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	//string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //s+="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	unordered_set<string> dic{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	vector<string> words=wordBreak(s,dic);
    for(auto& w : words){
          cout<<w<<endl;
   }
	return 0;
}