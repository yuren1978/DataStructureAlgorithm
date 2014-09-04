//http://zhedahht.blog.163.com/blog/static/254111742007376431815/
//：如果字符串一的所有字符按其在字符串中的顺序出现在另外一个字符串二中，则字符串一称之为字符串二的子串。注意，并不要求子串（字符串一）的字符必须连续出现在字符串二中。
//请编写一个函数，输入两个字符串，求它们的最长公共子串，并打印出最长公共子串。
//例如：输入两个字符串BDCABA和ABCBDAB，字符串BCBA和BDAB都是是它们的最长公共子串，则输出它们的长度4，并打印任意一个子串。
//分析：求最长公共子串（Longest Common Subsequence, LCS）是一道非常经典的动态规划题，因此一些重视算法的公司像MicroStrategy都把它当作面试题。

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

using namespace std;



int LcsContinueString(const string& A, const string& B){
	int m=A.size();
	int n=B.size();
	int result=0;
	vector<vector<int> > lcs(m+1, vector<int>(n+1,0));
	for(int i=0; i<=m; i++)
		for(int j=0;j<=n;j++){
			if(0==i ||0==j)
				lcs[i][j]=0;
			else if(A[i-1]==B[j-1]){
				lcs[i][j]=1+lcs[i-1][j-1];
				result=max(result, lcs[i][j]);
			}
			else{
				lcs[i][j]=0;
			}
		}
	return result;	
}

int main(int argc, char *argv[]) {
	string A = "OldSite:GeeksforGeeks.org";
    string B = "NewSite:GeeksQuiz.com";
    assert(10==LcsContinueString(A,B));
}