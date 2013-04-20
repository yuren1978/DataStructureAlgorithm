class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0||n==1){
            return n;
        }
        
        int current=A[0];
        int size=n;
        for(int i=1; i<size;){
            if(A[i]==current){
                for(int j=i; j<size-1; j++){
                    A[j]=A[j+1];
                }
                size--;
            }
            else{
                current=A[i];
                ++i;
            }
        }
        return size;
    }
};