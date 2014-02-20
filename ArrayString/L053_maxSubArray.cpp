class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxSum=INT_MIN;
        int sumSofar=0;
        for(int i=0; i<n; i++){
            sumSofar+=A[i];
            if(sumSofar>maxSum){
                maxSum=sumSofar;
            }
            if(sumSofar<0){
                sumSofar=0;
            }
        }
        return maxSum;
    }
};