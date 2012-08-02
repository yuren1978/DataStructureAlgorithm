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

int AddWithoutArithmetic(int num1, int num2)
{
        if(num2 == 0)
                return num1;
 
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
 
        return AddWithoutArithmetic(sum, carry);
}

int add(int a,int b){
    char * c;
    c = (char *) a;
    return &c[b];
}


int main(int argc, char *argv[]) {
	assert(10==AddNumber(3,7));
	assert(10==AddWithoutArithmetic(3,7));
	assert(4==AddWithoutArithmetic(-3,7));
	assert(4==add(-3,7));
}