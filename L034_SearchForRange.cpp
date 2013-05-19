class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        bool found=false;
        int start=0; int end=n-1; int middle=0;
        while(start<=end){
            middle=(start+end)/2;
            if(target==A[middle]){
                found=true;
                break;
            }
            else if(target>A[middle]){
                start=middle+1;
            }
            else{
                end=middle-1;
            }
        }
        
        if(found){
            start=middle;
            while(target==A[start]&&start>=0){
                start--;
            }
            end=middle;
            while(target==A[end]&&end<=n-1){
                end++;
            }
            v.push_back(start+1);
            v.push_back(end-1);
        }
        else{
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};