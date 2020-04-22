#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>

using namespace std;

void displayString(const vector<vector<string>>& accounts){
    for(const auto& ind: accounts){
        for(const auto& curr : ind){
            cout<< curr <<" '";
        }
        cout<<endl;
    }
}

string find(string s, map<string, string>& p){
    return p[s]==s ? s: find(p[s], p);
}

vector<vector<string>> accountMerge(vector<vector<string>>& accounts){
    //merge accounts
    map<string, string> owner;
    map<string, string> parents;
    map<string, set<string> > unions;
    vector<vector<string>> res;

    //set parents and owners
    for(int i=0; i<accounts.size(); i++){
        for(int j=1; j<accounts[i].size(); j++){
            parents[accounts[i][j]]=accounts[i][j];
            owner[accounts[i][j]]=accounts[i][0];
        }
    }

    for(int i=0; i<accounts.size(); i++){
        string p=find(accounts[i][1], parents);
        
    }

}


int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<string>> accounts={{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"},   {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    displayString(accounts);
    return 0;
}
