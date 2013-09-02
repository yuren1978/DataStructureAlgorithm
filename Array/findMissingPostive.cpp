#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int findMissingOneXOr(int A[], int n){
	int i;
	int x1=A[0]; //XOR element in array
	int x2=1;	 //XOR from 1 to n+1
	for (int i=1; i<n; ++i){
		x1=x1^A[i];
	}
	for( int i=2; i<=n; ++i){
		x2=x2^i;
	}
	return x1^x2;
}

int findMissingOneSwap(int A[], int n){
	int i=0;
	while (i < n) {
       if (A[i] != i+1 && A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i]) {
            swap(A[i], A[A[i]-1]);
        }
        else i++;
    }

    for (i = 0; i < n; i++)
        if (A[i] != i+1) break;
    return i+1;
}


void findMissingTwoSwap(int A[], int n){
	int i=0;
	while (i < n) {
       if (A[i] != i+1 && A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i]) {
            swap(A[i], A[A[i]-1]);
        }
        else i++;
    }
    for (int i = 0; i < n; ++i){
    	if(0==A[i]){
    		cout<<i+1<<endl;
    	}
    }
}

int main(){
	//int A1[]={1,2,0};
	//int A2[]={3,4,-1,1};

	//assert(3==findMissingPositive(A1, 3));
	//assert(2==findMissingPositive(A2, 4));
	int A1[]={2,3,0,4,5};
	assert(1==findMissingOneXOr(A1, 5)) ;
}