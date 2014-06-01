    #include <vector>
    #include <set>
    #include <string>
    #include <iostream>

    using namespace std;

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if(0==n) return v;
        if(1==n) {v.push_back("()"); return v; };
    
        set<string> stringSet;
        vector<string> lastVector=generateParenthesis(n-1);
        int size=lastVector.size();
        for(int i=0; i<size; i++){
            string lastString=lastVector[i];
            int stringSize=lastString.size();
            for(int j=0; j<stringSize; j++){
                string copyLastString=lastString;
                copyLastString.insert(j,"()");
                if(stringSet.find(copyLastString)==stringSet.end()){
                    stringSet.insert(copyLastString);
                }
            }
        }
        //convert set to vector
        for(auto& s : stringSet){
            v.push_back(s);
        }
        return v;
    }


    int main(int argc, char const *argv[])
    {
        vector<string> v=generateParenthesis(3);
        for(auto& s : v){
            cout<<s<<endl;
        }
    }