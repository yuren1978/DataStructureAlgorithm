#include <iostream>
#include <string>
#include <vector>

using namespace std;
//        n,k    k%n  
//1,2,3  (3,1)    0 
//1,3,2  (3,2)    0
//2,1,3  (3,3)    1
//2,3,1  (3,4)    1
//3,1,2  (3,5)    2  
//3,2,1  (3,6)    2

string convertVectorToString(const vector<int>& v){
    string s;
    for(auto i: v){
        s += to_string(i);
    }
    return s;
}

void rotate(vector<int>& v, int i, int j){
    if(i!=j){
        int t=v[j];
        for (int k = j; k > i; --k){
            v[k]=v[k-1];
        }
        v[i]=t;
    }
}

string getPermutation(int n, int k) {
    //initialize the string.
    vector<int> v;
    for (int i = 1; i <= n; ++i){
        v.push_back(i);
    }
    int mod=1;
    for (int i = 1; i <n; ++i){
        mod=mod*i;
    }
    int s=0;

    while(s<n-1){
        int pos=(k-1)/mod+s;
        rotate(v, s++, pos);
        k=(k-1)%mod+1;        
        mod=mod/(n-s);
    }

    string ps = convertVectorToString(v);
    return ps;
}

int main(int argc, char const *argv[])
{
    cout<< getPermutation(3,1) <<endl;
    cout<< getPermutation(3,2) <<endl;
	cout<< getPermutation(3,3) <<endl;
    cout<< getPermutation(3,4) <<endl;
    cout<< getPermutation(3,5) <<endl;
    cout<< getPermutation(3,6) <<endl;
	return 0;
}