#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string sortABasedOnB(const string& a, const string& b){
	map<char, int> mp;
	map<int, char> rmp;

	int count=0;
	for(char c:b){
		if(mp.find(c)==mp.end()){					
			mp[c]=count;
			rmp[count]=c;
			count++;
		}
	}



	string middleString;
	for(char c:a){
		if(mp.find(c)!=mp.end()){
			middleString+=mp[c];
		}
		else
			middleString+=c;
	}
	
	sort(middleString.begin(), middleString.end());
	
	string returnString;
	for(char c:middleString){
		if(rmp.find(c)!=rmp.end())
			returnString+=rmp[c];
		else
			returnString+=c;
	}

	return returnString;
}


int main(int argc, char const *argv[])
{
	string a="cat";
	string b="tar";
	cout<<sortABasedOnB(a,b)<<endl;
	return 0;
}