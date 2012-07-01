#include <stdio.h>

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9};
	int b[]={6,8,9,10,11,12};
	int* pa=a;
	int* pb=b;
	int sizeOfa=sizeof(a)/sizeof(*a);
	int sizeOfb=sizeof(b)/sizeof(*b);
	int indexOfa=0;
	int indexOfb=0;
	
	while (indexOfa<sizeOfa && indexOfb<sizeOfb ) {
		if(*pa<*pb){
			indexOfa++;
			pa++;
		}
		else if(*pa>*pb){
			indexOfb++;
			pb++;
		}
		else{
			printf("%d",*pa);
			pa++;
			pb++;
			indexOfa++;
			indexOfb++;
		}
	} 
}