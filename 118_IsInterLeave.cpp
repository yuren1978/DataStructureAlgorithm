//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
#include <iostream>
#include <cassert>
#include <set>

using namespace std;


void CombineString(int i1, int i2, int length1, int length2, string s1, string s2, string s3, string combineString, set<string>&  setStrings)
{
	if(s3.substr(0, i1+i2)!=combineString){
		return;
	}
	
	if(i1==length1||i2==length2){
		if(i1==length1){
			combineString.append(s2.substr(i2,string::npos));
			setStrings.insert(combineString);		}
		else {
			combineString.append(s1.substr(i1,string::npos));
			setStrings.insert(combineString);
		}	
		return;
	}
	
	
	
	CombineString(i1+1, i2, length1, length2, s1, s2, s3, combineString+s1[i1], setStrings);
	CombineString(i1, i2+1, length1, length2, s1, s2, s3, combineString+s2[i2], setStrings);
	
}

bool isInterleave(string s1, string s2, string s3) {
	set<string> setStrings;
	CombineString(0,0, s1.size(), s2.size(), s1,s2, s3, "", setStrings);
	return setStrings.find(s3)!=setStrings.end();
}

int main(int argc, char *argv[]) {
	assert(isInterleave("a","b","ab")); 
}