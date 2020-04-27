#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int> converVector(const vector<int>&  v){
    map<int, int> mp;
    int size=v.size();
    for(int i=0; i<size; i++){
        mp[i]=v[i];
    }
    return mp;
}


int getProduct(const vector<int>& v1, const vector<int>& v2){
    //convert to (index,value)
    map<int,int> mp1= converVector(v1);
    map<int,int> mp2= converVector(v2);

    int sum=0;
    for(auto const& [key,val]: mp1){
        if(mp2.count(key))
            sum += val * mp2[key];
    }
    return sum;
}


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v1 {1,0,0,0,4,0,1};
    vector<int> v2 {0,0,0,0,3,0,0};
    int product=getProduct(v1,v2);
    cout<< " Product is "<< product <<endl;
    return 0;
}
