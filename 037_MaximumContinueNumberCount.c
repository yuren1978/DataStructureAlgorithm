//http://www.mitbbs.com/article_t1/JobHunting/32156867_0_1.html
//1.求一个数字数组里的最大连续数字的个数。
//3, 4, 4, 4, 2, 2, 3, 4  =>  return 3

#include <stdio.h>
#include <assert.h>

int GetMaximumCount(int a[], int length){

}

int main(int argc, char *argv[]) {
	int a[]={3, 4, 4, 4, 2, 2, 3, 4};
	int length=sizeof(a)/sizeof(*a);
	int maxCount=GetMaximumCount(a, length);
	printf("count is %d", maxCount);
	//assert(3==GetMaximumCount(a,length));
	return 0;
}

