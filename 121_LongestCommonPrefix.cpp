#include <iostream>
#include <vector>

using namespace std;

string GetMinLengthString(const vector<string> &strs)
{	
	size_t stringSize=strs.size();
	string minString=strs[0];
	for (size_t i=1; i<stringSize; i++) {
		string currentString=strs[i];				if(currentString.size()<minString.size()){
			minString=currentString;
		}
	}
	return minString;
}

int GetCommonLength(const string& minString, const vector<string> &strs){
	size_t stringSize=strs.size(); 
	int minSize=minString.size();
		for (int i=0; i<minSize; i++) {
			char current=minString[i];
			for (size_t j=0; j<stringSize; j++) {
				if(strs[j][i]!=current){
					return i;	
				}	
			}
		} 
	return minSize;	    	
}

string longestCommonPrefix(vector<string> &strs) {
	string commonPrefix;
	size_t stringSize=strs.size(); 
	if(stringSize==0){
		return "";
	}	
	string minString=GetMinLengthString(strs);
	int commoneLength=GetCommonLength(minString, strs);
	return minString.substr(0, commoneLength);	
}

int main(int argc, char *argv[]) {
	
}


