
//http://effprog.blogspot.com/2012/04/to-find-max-palindrome-in-given-string.html?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+EffectiveProgramming+%28Effective+Programming%29



#include <stdio.h>

int main(int argc, char *argv[]) {

 	assert(largestPalindrome("a") == "a");
    assert(largestPalindrome("sa") == "s");
    assert(largestPalindrome("aa") == "aa");
    assert(largestPalindrome("aaa") == "aaa");
    assert(largestPalindrome("aba") == "aba");
    assert(largestPalindrome("abba") == "abba");
    assert(largestPalindrome("aaaa") == "aaaa");
    assert(largestPalindrome("aaaaa") == "aaaaa");
    assert(largestPalindrome("aabaa") == "aabaa");
    assert(largestPalindrome("sambasiva") == "s");
    assert(largestPalindrome("sambabmiv") == "mbabm");
    assert(largestPalindrome("saaasr") == "saaas");
    assert(largestPalindrome("saasr") == "saas");

    cout<< "All tests passed" << endl;	
}