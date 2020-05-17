#include<vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void buildAccountMap(const vector<vector<string>>& accounts ,
    map<string, set<string> >& accountMap,
    map<string, string>& emailMap ){
    for(const vector<string>& accountLine: accounts){
        string name=accountLine[0];
        for(int i=1; i<accountLine.size(); i++){
            string email=accountLine[i];
            emailMap[email]=name;
            if(accountMap.find(email)==accountMap.end()){
                set<string> associatedSet;
                accountMap[email]=associatedSet;
            }
            if(i>1){//inser the edge to set
                accountMap[email].insert(accountLine[i-1]);
                accountMap[accountLine[i-1]].insert(email);
            }
        }
    }    
}
    
void dfs(map<string, set<string> > & accountMp, string key, vector<string>& currentSet, set<string>& visited){
    cout<<key<<endl;
    visited.insert(key);
    currentSet.push_back(key);
    set<string> connectedEmails=accountMp[key];
    for(string connectedEmail: connectedEmails){
        if(!visited.count(connectedEmail)){
            dfs(accountMp, connectedEmail, currentSet, visited);
        }
    }
}
    
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, set<string> > accountMp;
    map<string, string> emailMp;
    buildAccountMap(accounts, accountMp, emailMp);
    vector<vector<string>> results;
    //loop through map
    set<string> visited;
    for(auto const& [key, val]: accountMp){
        if(!visited.count(key)){//this key hasn't been visited
            vector<string> currentSet;
            dfs(accountMp, key, currentSet, visited);
            sort(currentSet.begin(),currentSet.end());
            string name=emailMp[currentSet[0]];
            currentSet.insert(currentSet.begin(), name);
            results.push_back(currentSet);
        }
    }
    return results;
}

int main(int argc, char const *argv[])
{
    vector<vector<string>>  accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    vector<vector<string>> mergedAccounts = accountsMerge(accounts);
    for(vector<string>& mergeAccontLine:mergedAccounts ){
        for (size_t i = 0; i < count; i++)
        {
            /* code */
        }
        
        cout<<endl;
    }
    return 0;
}
