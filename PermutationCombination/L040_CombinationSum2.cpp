class Solution {
public:
    bool vectorEqual(const vector<int>& v, const vector<int>& cv){
        if(v.size()==cv.size()){
            for(int i=0; i<v.size(); i++){
                if(v[i]!=cv[i]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    bool existing(const vector<vector<int> >& v, const vector<int>& cv){
        int size=v.size();
        for(int i=0; i<size; i++){
            if(vectorEqual(v[i], cv)){
                return true;
            }
        }
        return false;
    }

    void combinationSum2DFS(vector<int> &num, vector<vector<int> >& v, int index, int sum, vector<int> &numSelection, int target ){
        if(sum>target){
            return;
        }
        else if(sum==target){
            if(!existing(v, numSelection)){
                v.push_back(numSelection);
            }
            
            return;
        }
      
        for(int i=index; i<num.size(); i++){
            sum+=num[i];
            numSelection.push_back(num[i]);
            
            combinationSum2DFS(num, v, i+1, sum,numSelection, target);
            sum-=num[i];
            numSelection.pop_back();
        }
        
    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        vector<vector<int> > v;
        vector<int> currentV;
        combinationSum2DFS(num, v, 0, 0, currentV, target );
        return v;
    }
};