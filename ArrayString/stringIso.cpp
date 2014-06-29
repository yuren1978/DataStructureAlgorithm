#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;


int distinctCharCount(string s){
	set<char> charSet;
	for(int i=0; i<s.size(); i++)
		charSet.insert(s[i]);
	return charSet.size();
}


bool isomorphic(string s1, string s2){
	if(s1.size()!=s2.size())
		return false;

	if(distinctCharCount(s1)!=distinctCharCount(s2))
		return false;

	map<char,char> isomorphicMaps;
	for (int i = 0; i <s1.size() ; ++i){
		if(isomorphicMaps.find(s1[i])!=isomorphicMaps.end() && isomorphicMaps[s1[i]]!=s2[i]){
				return false;
		}
		else{
			isomorphicMaps[s1[i]]=s2[i];
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	cout<<isomorphic("zoo","fee")<<endl;
	cout<<isomorphic("zoo","dui")<<endl;
	cout<<isomorphic("dui","zoo")<<endl;

	return 0;
}