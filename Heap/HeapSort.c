#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

void printArray(int a[], int n){
	cout<<"print array " ;
	for (int i = 0; i < n; ++i){
		cout<<a[i];
	}
	cout<<endl;
}



void shiftDown(int a[], int n, int k){
	int currentNum=a[k];
	while(k<n){
		int maxK=k;
		int left=2*k+1;
		int right=2*k+2;
		if(left<n && a[left] >a[maxK]){
			maxK=left;
		}	
		if(right<n && a[right]>a[maxK]){
			maxK=right;
		}
		if(maxK==k){//didn't find any child bigger
			break;
		}
		else{
			int temp=a[k];
			a[k]=a[maxK];
			a[maxK]=temp;	
			k=maxK;
		}
	}
}

void assertHeap(int a[], int i, int n){
	int left=2*i+1;
	int right=2*i+2;
	if(left<n){
		assert(a[i]>a[left]);
	}
	if(right<n){
		assert(a[i]>a[right]);
	}
}

void swap(int a[], int m, int n){
	int temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}

void heapSortAscending(int a[], int n){
	for(int k=n/2-1; k>=0; k--){
		shiftDown(a, n, k);
	}

	for (int i = 0; i <=n/2-1 ; ++i){
		assertHeap(a, i, n);
	}
	//printArray(a, n);

	//get max element at top.`
	int k=n-1;
	while(k>0){
		swap(a, 0, k); // move a[k] to the end.
		shiftDown(a, k, 0);
		k--;
	}
	printArray(a, n);
}

int main(int argc, char *argv[]) {
	int a[]={2, 1, 7, 6, 3, 4};
	heapSortAscending(a, 6);
}