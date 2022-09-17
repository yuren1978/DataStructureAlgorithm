#include <cstdio>
#include <cassert>
#include <queue>
#include <iostream>
#include <unordered_map>

using namespace std;


int main(int argc, char const *argv[])
{
    unordered_map<int, priority_queue<pair<int, int>>> tweets;
    tweets[1].push({2,2});
    tweets[1].push({1,1});
    tweets[1].push({1,1});
    cout<<"tweet counts "<<tweets.size()<<endl;
    for(const auto& [k,v]: tweets){
        cout<<" key "<< k<<endl;
        cout<<" val "<< v.top().first << " "<< v.top().second<< endl;
    }
    /* code */
    return 0;
}
