#include <iostream>
#include <cassert>

using namespace std;

int search(int A[], int n, int target) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
	int start=0; int end=n-1;
	while (start<end) {
		//printf("start %d end %d\n", start, end);
		int middle=(start+end)/2;
		if(target==A[middle]){
			return middle;
		}
		else {
			if(A[middle]<A[end]){
				if(target>A[middle] && target <=A[end]){
					start=middle+1;
				}
				else {
					end=middle-1;
				}
			}
			else {
				if(target<A[middle] && target>=A[start]){
					end=middle-1;
				}
				else{
					start=middle+1;
				}
			}
		}		
	}
	if(target==A[start])
		return start;
	return -1;     
}

int main(int argc, char *argv[]) {
	int A[]={4,5,6,7,0,1,2}; 
	assert(4==search(A, 7, 0));
}