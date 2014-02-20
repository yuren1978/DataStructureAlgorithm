#include <iostream>
#include <cassert>

int findPivotPoint(int A[], int n){
	int l=0; int r=n-1;
	while(A[l]>A[r]){
		int m=l+(r-l)/2;
		if(A[m]>A[r]){
			l=m+1;
		}
		else{
			r=m;
		}
	}
	return l;
}

int main(){
	int A1[]={5,4,1,2,3};
	assert(2==findPivotPoint(A1,5));
	return 0;
}