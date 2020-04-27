#include <cstdio>
#include <cstdlib>
#include <cassert>


int FindMinNumber(int* array, int length){
	int start=0, end=length-1;
	while (start<end) {
		int middle=(start+end)/2;
		if(array[start]<array[middle]){
			if(array[start]<array[end] && array[start]<array[middle+1]){
				end=middle;
			}
			else {
				start=middle+1;
			}	
		}
		else {
			if(array[middle+1]<array[start] && array[middle+1]<array[middle]){
				start=middle+1;	
			}
			else {
				end=middle;
			}
		}
	}
	return array[start];	
}

int main(int argc, char *argv[]) {
	int a[]={4,5,6,7,8,9,10, 1,2,3};
	int length=sizeof(a)/sizeof(*a);
	assert(1==FindMinNumber(a, length));
	int b[]={1,2,3,4,5,6,7,8,9,10};
	length=sizeof(b)/sizeof(*b);
	assert(1==FindMinNumber(b, length));
	
}