class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=n;
        for(int i=0; i<size;){
            if(elem==A[i]){
                for(int j=i; j<size-1; ++j){
                    A[j]=A[j+1];
                }
                size--;
            }
            else{
                ++i;
            }
        }
        return size;
    }
};