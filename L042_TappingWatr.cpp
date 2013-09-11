#include <iostream>

using namespace std;

int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int max=0;
        int* left=new int[n];
        for(int i=0; i<n; ++i){
            left[i]=max;
            if(A[i]>max){
                max=A[i];
            }
        }
        
        int sum=0;
        max=0;
        for(int i=n-1; i>=0; --i){
            int minHeight=left[i]<max? left[i]:max;
            if(minHeight>A[i]){
                sum+=(minHeight-A[i]);
            }
            if(A[i]>max){
                max=A[i];
            }
        }
		delete[] left;        
        return sum;
    }

int main(int argc, char *argv[]) {
	int A[]={2,0,2};
	int trapWater=trap(A, 3);
	cout<<trapWater<<endl;
}