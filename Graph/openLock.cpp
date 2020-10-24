#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

 char getLeft(char c){
        char lc;
        if(c=='0')
            lc='9';
        else
            lc=c-1;
        return lc;
    }
    
    char getRight(char c){
        char rc;
        if(c=='9')
            rc='0';
        else
            rc=c+1;
        return rc;
    }
    
    
    vector<string> getNeighbors(string current){
        vector<string> neighbors;
        int size=current.size();
        for(int i=0; i<size; i++){
            string left=current.substr(0,i);
            string right=current.substr(i+1);
            char lc=getLeft(current[i]);
            char rc=getRight(current[i]);
            string ls=left+lc+right;
            string rs=left+rc+right;
            //cout<<ls<<endl;
            //cout<<rs<<endl;
            neighbors.push_back(ls);
            neighbors.push_back(rs);
        }
        return neighbors;
    }
    
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        queue<string> q;
        map<string, int> mp;
        q.push("0000");
        mp["0000"]=0;
        while(!q.empty()){
            string current=q.front();
            q.pop();
            int dis=mp[current];
            if(current==target)
                return dis;
            vector<string> neighbors=getNeighbors(current);
            for(auto neighbor: neighbors){
                if(deadset.count(neighbor)==0 && mp.count(neighbor)==0){
                    q.push(neighbor);
                    mp[neighbor]=dis+1;
                }
            }
        }
        return -1;
    }

int main(int argc, char const *argv[])
{
    /* code */
    vector<string> deadends = {"0000"};
    int distance=openLock(deadends, "8888");
    cout<<distance<<endl;
    return 0;
}
