class Solution {
public:
    string getKey(string currentString){
        sort(currentString.begin(), currentString.end());
        return currentString;
    }

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> anagrams;
        vector<pair<string,string>> keyedStrings;
        map<string, int> keyCount;
        int size=strs.size();
        for(int i=0; i<size; ++i){
            string key= getKey(strs[i]);
            if(keyCount.find(key)!=keyCount.end()){
                keyCount[key]++;
            }
            else{
                keyCount[key]=1;
            }
            
            keyedStrings.push_back(make_pair(key, strs[i]));
        }
        
        for(int i=0; i<size; ++i){
            pair<string,string> keyPair=keyedStrings[i];
            if(keyCount[keyPair.first]>1){
                anagrams.push_back(keyPair.second);
            }
        }
        return anagrams;
    }
};