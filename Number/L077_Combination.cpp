class Solution {
public:
    void combineDFS(int n, int k, int currentIndex, vector<int>& v,  vector<vector<int> >& results){
        if(v.size()==k){
            results.push_back(v);
            return;
        }
        
        for(int i=currentIndex; i<n; i++){
            v.push_back(i+1);
            combineDFS(n, k, i+1, v, results);
            v.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        vector<vector<int> > results;
        combineDFS(n, k, 0, v, results);
        return results;
    }
};