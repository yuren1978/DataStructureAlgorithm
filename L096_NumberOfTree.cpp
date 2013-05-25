class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int* A=new int[n+1];
        for(int i=0; i<=n; i++){
            A[i]=0;
        }
        A[0]=1;A[1]=1; A[2]=2;
        for(int i=3; i<=n; i++){
            for(int j=0; j<i; j++){
                A[i]+=A[j]*A[i-1-j];
            }
        }
        return A[n];
    }
};