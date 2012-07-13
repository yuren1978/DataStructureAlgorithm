//http://www.leetcode.com/2011/11/longest-palindromic-substring-part-i.html?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+ihas1337code+%28LeetCode%29
//http://effprog.blogspot.com/2012/04/to-find-max-palindrome-in-given-string.html?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+EffectiveProgramming+%28Effective+Programming%29

using System;
using System.Diagostics;
using System.Collectons.Generic;


class LongestPalindrom{
	
	string largestPalindrome(string inputString){
		int length=inputString.Length;
		if(length<=1){
			return inputString;
		}
		string palinString=inputString.SubString(0,1);
		for (int i=0; i<length-1; i++) {
			string oddPalinDrom=GetPalindromFromCenter(inputString, i,i);
			if(oddPalinDrom.Length>palinString.Length){
				palinString=oddPalinDrom;
			}
			string evenPalinDrom=GetPalindromFromCenter(inputString, i, i+1);
			if(evenPalinDrom.Length>palinString.Length){
				palinString=evenPalinDrom;
			}
		}
		return palinString;
	}
	
	static void Main(){
			Debug.Assert(largestPalindrome("a") == "a");
		    Debug.Assert(largestPalindrome("sa") == "s");
		    Debug.Assert(largestPalindrome("aa") == "aa");
		    Debug.Assert(largestPalindrome("aaa") == "aaa");
		    Debug.Assert(largestPalindrome("aba") == "aba");
		    Debug.Assert(largestPalindrome("abba") == "abba");
		    Debug.Assert(largestPalindrome("aaaa") == "aaaa");
		    Debug.Assert(largestPalindrome("aaaaa") == "aaaaa");
		    Debug.Assert(largestPalindrome("aabaa") == "aabaa");
		    Debug.Assert(largestPalindrome("sambasiva") == "s");
		    Debug.Assert(largestPalindrome("sambabmiv") == "mbabm");
		    Debug.Assert(largestPalindrome("saaasr") == "saaas");
		    Debug.Assert(largestPalindrome("saasr") == "saas");

	}
}


