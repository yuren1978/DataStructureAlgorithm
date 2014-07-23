#include <iostream>
#include <algorithm>

using namespace std;

void swap(int a[], int l, int r){
	int temp=a[l];
	a[l]=a[r];
	a[r]=temp;
}

void printArray(int a[], int size){
	cout<<"Array : ";
	for(int i=0; i<size; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
}

void twoWayPartition(int * low, int * high, int pivot) {
	for(int *p=low; p<high;p++){
		if(*p<pivot){
			swap(*low++, *p);
		}
	}
}

void threeWayPartition(int * low, int * high, int pivot) {
    for (int *p = low; p < high; ) {
        if (*p == pivot)
            ++p;
        else if (*p < pivot)
            swap(*low++, *p++);
        else
            swap(*p, *--high);
    }
}



int main(int argc, char const *argv[])
{
	int a[]={3,4, 9,7,2,8,7,100};
	int size=sizeof(a)/sizeof(*a);
	printArray(a,size);
	threeWayPartition(a, a+(size-1),7);
	printArray(a,size);


	int b[]={3,4, 9,6,2,8,7,100};
	size=sizeof(b)/sizeof(*b);
	printArray(b,size);
	twoWayPartition(b, b+(size-1),7);
	printArray(b,size);
	return 0;
}