//http://www.leetcode.com/2011/01/double-square-problem-analysis.html
//A double-square number is an integer X which can be expressed as the sum of two perfect squares. For example, 10 is a double-square because 10 = 32 + 12. Your task in this problem is, given X, determine the number of ways in which it can be written as the sum of two squares. For example, 10 can only be written as 32 + 12 (we don’t count 12 + 32 as being different). On the other hand, 25 can be written as 52 + 02 or as 42 + 32.



#include <cstdio>
#include <cassert>
//#include <cmath>


int doubleSquare(unsigned int m) {
  int total = 0;
  int iUpper = sqrt((double)m );
  printf("iUpper is %d\n", iUpper);	
  for (int i = 0; i <= iUpper; i++) {
	printf("i is %d \n", i);
    unsigned int ii = i*i;
    for (int j = i; ; j++) {
      unsigned int sum = ii + j*j;
      if (sum == m){
			printf("%d and %d \n", i,j);
	 		total++;
       }       
      else if (sum > m)
        break;
    }
  }
  return total;
}

int main(int argc, char *argv[]) {
	//assert(1==doubleSquare(10));
	assert(2==doubleSquare(100));
}