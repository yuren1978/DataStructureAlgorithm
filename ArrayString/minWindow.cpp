    #include <string>
    #include <map>
    using namespace std;
    
    string minWindow(string s, string t) {
        map<char, int> mp;
        for(char s: t){
            mp[s]++;
        }
        string minWindowString;
        int minWindow=-1;
        int counter=mp.size();
        int start=0, end=0;
        while(end<s.size()){
            if(mp.count(s[end])){
                mp[s[end]]--;   // it can go to negative
                if(mp[s[end]]==0)
                    counter--;
            }
            end++;
            
            while(counter==0){//all characters have been identified.
                if(mp.count(s[start])){
                    mp[s[start]]++;
                    if(mp[s[start]]>0)
                        counter++;
                }
                if((end-start)<minWindow){
                    minWindow=end-start;
                    minWindowString=s.substr(start, end-start);
                }
                start++;
            }
        }
        return minWindowString;
    }

int main(int argc, char const *argv[])
{
    /* code */
    string minWid=minWindow("ADOBECODEBANC","ABC")
    return 0;
}
