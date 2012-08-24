//http://www.mitbbs.com/article_t/JobHunting/31342084.html
//1. 一个sorted interger Array[1...N], 已知范围 1...N+1. 已知一个数字missing。
//   找该数字。 
//   把原题改为unsorted，找missing数字。 performance。
#include <stdio.h>
#include <assert.h>

int firstMissingPositive(int A[], int n) 
{

}

int firstMissingPositiveXOr(int a[], int length){
}

int main(int argc, char *argv[]) {
	int a[]={3,2,1,5}; //the range is from 1 to 7
	int length=sizeof(a)/sizeof(*a);
	
	assert(4==firstMissingPositiveXOr(a, length));
	//assert(4==firstMissingPositive(a, length));
}