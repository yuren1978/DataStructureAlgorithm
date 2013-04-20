#include <stdio.h>
#include <assert.h>

// int AddNumber(int a, int b){
// }

// int AddWithoutArithmetic(int num1, int num2)
// {
// }

int add(int a,int b){
    //char * c;
    char* c = (char *) a;
    return &c[b];
}


int main(int argc, char *argv[]) {
	assert(10==add(3,7));
	//assert(10==AddWithoutArithmetic(3,7));
	//assert(4==AddWithoutArithmetic(-3,7));
	assert(4==add(-3,7));
}