//http://www.leetcode.com/2012/01/palindrome-number.html?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+ihas1337code+%28LeetCode%29

#include <stdio.h> 
#include <assert.h>

typedef enum {false, true} bool;
//test
//Determine whether an integer is a palindrome. Do this without extra space.
bool isPalindrome(int x) {
  if (x < 0) return false;
  int div = 1;
  while (x / div >= 10) {
    div *= 10;
  }
  while (x != 0) {
	
    int l = x / div;
    int r = x % 10;
   printf("\n x is %d div is %d left is %d and right is %d", x, div, l, r);
	 if (l != r) return false;
    x = (x % div) / 10;
    div /= 100;
  }
  return true;
}


int main(int argc, char *argv[]) {
	printf("\n Test palindrom");
	assert(true==isPalindrome(12321));
}