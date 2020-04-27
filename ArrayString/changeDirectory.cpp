#include <string>
#include <vector>
#include <iostream>
#include <sstream>  
using namespace std;

string changePath2(string& current, string& change)
{
   for(int i=0, n=change.size(); i<n;){
		while(i<n && change[i]=='/')++i;
		string dir;
		while(i<n && change[i]!='/')
			dir += change[i++];
        
        //decision based dir value
		if (dir == ".") continue;
		if (dir == "..") {
			while(current.back()!='/')
				current.pop_back();
			if(current.size()>1) 
            current.pop_back();//pops slash but not the root slash
		} else {
			if(current.back()!='/') current += '/';
			current += dir;
		}
	}
    return current;
}

string changePath(string& current, string& change)
{
    vector<string> st;
    string str;
    for(stringstream ss(current); getline(ss, str, '/');)
        if(str.size()) st.push_back(str);
    for(stringstream ss(change); getline(ss, str, '/');)
    {
        if(str.empty() || str == ".") continue;
        if(str != "..") st.push_back(str);
        else if(st.size()) st.pop_back();
    }
    str.erase();
    for(auto& s : st) str += "/" + s;
    return str.size() ? str : "/";
}


int main(int argc, char const *argv[])
{
    /* code */
    string current="/facebook/anin";
    string change="../abc/def ";
    string changedPath=changePath2(current, change);
    cout<<changedPath;
    return 0;
}
