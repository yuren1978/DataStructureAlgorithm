//第四轮让你返回两个array的common的元素，用O(n)两种方法做，如果有duplicate，要
//打出greatest common 个数，如果第一个数组有3个3，第二个数组有2个3，最后打印出来2个3

#include <stdio.h>

void FindCommonElements(int* a, int lengthOfA, int* b, int lenthOfB){
	int i, j;
	i=0;j=0;
	while (i<lengthOfA || j<lenthOfB) {
		if(a[i]<b[j]){
			i++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else {
			printf("%d\t",a[i]);
			i++;
			j++;
		}
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,2,2,5,5,6,8,9};
	int b[]={2,5,5,5,8,9};	
	int lengthOfA=sizeof(a)/sizeof(*a);
	int lengthOfB=sizeof(b)/sizeof(*b);
	FindCommonElements(a, lengthOfA, b, lengthOfB);
}


