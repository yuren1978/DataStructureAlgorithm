class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;     
        for(int i=0; i<n; ++i){
            if(target<=A[i]){
                return i;
            }
        }
        return n;
    }
};