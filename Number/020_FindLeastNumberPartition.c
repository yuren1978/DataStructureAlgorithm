#include <stdio.h>
#include <stdlib.h>

void Swap(int* input, int i, int j){
	int temp=input[i];
	input[i]=input[j];
	input[j]=temp;
}

int Partition(int* input, int n, int start, int end){
	int i, j, pivotItem;
	j=start;
	pivotItem=input[start];
	for (i=start+1; i<=end; i++) {
		if(input[i]<pivotItem){
			j++;
			Swap(input, i, j);
		}
	}
	Swap(input, start, j);
	return j;
}

void GetLeastNumbers(int* input, int n, int* output, int k)
{
    if(input == NULL || output == NULL || k > n || n <= 0 || k <= 0)
        return;

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while(index != k - 1)
    {
        if(index > k - 1)
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }

    for(int i = 0; i < k; ++i)
        output[i] = input[i];
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int b[]={0,0,0,0};
	GetLeastNumbers(a,8,b,4);
	for (int i=0; i<4; i++) {
		printf("%d", b[i]);
	}
}