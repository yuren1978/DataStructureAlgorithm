#include <stdio.h>

void reverse(int* a, int start, int end)
{
	while(start<end){
		int temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}

void rotate(int* a, int n, int k){
 	reverse(a, 0, n-1);
    reverse(a, 0, k-1);
    reverse(a, k, n-1);
}

int main(int argc, char const *argv[])
{
	int k=3;
	int n=10;
	int a[]={1,2,3,4,5,6,7,8,9,10};
   	rotate(a, n, k);
    for (int i = 0; i < n; ++i)
    {
    	printf("%d\t", a[i]);
    }
	return 0;
}