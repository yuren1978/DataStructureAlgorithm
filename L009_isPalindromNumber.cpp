#include <cstdio>
#include <ctype.h>
#include <cassert>
#include <string>

#include <iostream>

using namespace std;
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.

	int getHighOrders(int number){
		int step=10;
		while(number/step>0){
			step=step*10;
		}
		return number;
	}

	bool isPalindromePositiveNumber(int number){
		int highOrder=getHighOrders(number);
		int lowerOrder=10;
		while(lowerOrder<=highOder){
			int lowerDigit=number % lowerOrder;
			int highDigit= number/highOder;
			if(lowerDigit!=highDigit){
				return false;
			}
			number=number-highDigit;
			number=number/lowerDigit;
		}
		return true;
	}

    bool isPalindromeNumber(int number) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(number>=0 && number<=10)
			return true;

		return number<0 ?isPalindromePositiveNumber(-number) : isPalindromePositiveNumber(number);
	}


int main(int argc, char *argv[]) {
	assert(isPalindromeNumber("1"));
	assert(isPalindromeNumber("123"));
	//assert(!isPalindrome("race a car"));
}
