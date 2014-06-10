#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



vector<vector<int> > subsets2(vector<int>& vec){
    int length=vec.size();
    vector<vector<int> > v;
    int number=std::pow(2.0,length);
    for (int i=1; i<number; i++) {
        vector<int> currentVector;
        for (int j=0; j<length; j++) {
            if((i>>j)&1){
                currentVector.push_back(vec[j]);
            }
        }
        v.push_back(currentVector);
    }
    return v;
}


void subsets(vector<int> &S, int startIndex, vector<int>& v , vector<vector<int> >& results, int size){

    if(size==v.size())
        results.push_back(v);
    
    for(int i=startIndex; i<S.size(); i++){
        v.push_back(S[i]);
        subsets(S, i+1, v, results,size);
        v.pop_back();
    }
}



vector<vector<int> > subsets(vector<int> &S, int size) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    sort(S.begin(), S.end());
    vector<vector<int> > results;
    vector<int> v;
    subsets(S, 0 , v, results, size);
    return results;
}

void printVector(const vector<int>& v){
	int size=v.size();
	for (int i=0; i<size; i++) {
		printf("%d ", v[i]);
	}
}


void subsetStrings(const string& s, int startIndex, string currentS, vector<string>& results ){
    results.push_back(currentS);

    for (int i = startIndex; i < s.size(); ++i){
        currentS.push_back(s[i]);
        subsetStrings(s, i+1, currentS, results);
        currentS.pop_back();
    }
} 

vector<string> subsetStrings(const string& s){
    vector<string> results;
    string currentS;
    subsetStrings(s, 0, currentS, results);
    return results;
}


int main(int argc, char *argv[]) {
	// vector<int> v;
	// v.push_back(1);
	// v.push_back(2);
	// v.push_back(3);

	
	// vector<vector<int> > s=subsets2(v);
	// int size=s.size();
	// for(int i=0; i<size; i++){
	// 	printVector(s[i]);
	// 	printf("\n");
	// }

    string inputString("abc");
    vector<string> stringVector=subsetStrings(inputString);
    for (auto& s : stringVector){
        cout<<s<<endl;
    }
}