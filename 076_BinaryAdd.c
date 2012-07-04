#include <stdio.h>
#include <assert.h>

int AddNumber(int a, int b){
	int sum;
	int carry;
	do {
		sum=a^b;
		carry=(a&b)<<1;
		
		a=sum;
		b=carry;
	} while (carry>0);
	return sum;
}

int main(int argc, char *argv[]) {
	assert(10==AddNumber(3,7));
	//assert(4==AddNumber(-3,7));
}