//http://stackoverflow.com/questions/249423/how-does-xor-variable-swapping-work
#include <stdio.h>
#include <assert.h>

int Swap(int* x, int* y){
	*x=(*x)^(*y);
	*y=(*x)^(*y);
	*x=(*x)^(*y);
	return 0;
}

int main(int argc, char *argv[]) {
	int a=2, b=3;
	Swap(&a, &b);
	assert(3==a);
	assert(2==b);
}