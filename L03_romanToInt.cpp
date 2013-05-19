#include <iostream>
#include <string>
#include <map>


using namespace std;


int romanToInt(string s) {
    int result = 0;
    map<char, int> lookup;
    lookup['I'] = 1; 
	lookup['V'] = 5; 
	lookup['X'] = 10; 
	lookup['L'] = 50; 
	lookup['C'] = 100; 
	lookup['D'] = 500;
	lookup['M'] = 1000;
    for(int i = 0; i < s.size() -1; i++)
    {
        if(lookup[s[i]] < lookup[s[i+1]])
            result -= lookup[s[i]];
        else
            result += lookup[s[i]];
    }
    result += lookup[s[s.size()-1]];
    return result;
}


int main(int argc, char *argv[]) {
	cout<<romanToInt("IV")<<endl;
}