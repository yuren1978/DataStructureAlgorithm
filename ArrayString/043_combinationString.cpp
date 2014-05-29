//http://zhedahht.blog.163.com/blog/static/2541117420114172812217/
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//用一个数组，模拟2进制加法器，某一个为1，则取对应的字符，若为0则不取，就能够实现字符组合。
//a,b,c, ab, ac, bc, abc

void CombinationNumber(const char* cur, int length)
{
	int number=std::pow(2.0,length);
	for (int i=1; i<number; i++) { // 001, 010, 011, 100, 101, 110, 111
		for (int j=0; j<length; j++) {
			if((i>>j)&1){ //understand this condition
				printf("%c ", *(cur+j));
			}
		}
		printf("\n");
	}
}

void Combination(const char* cur, vector<char>& result)
{
	 if(*cur == '\0')
	 {
	  	vector<char>::iterator iter = result.begin();
	  	for(; iter < result.end(); ++ iter)
	   		printf("%c", *iter);
	  	printf("\n");
	  	return;
	 }
	 result.push_back(*cur);
 	 Combination(cur + 1, result);
 	 result.pop_back();
 	 Combination(cur+1, result);
}


int main(int argc, char *argv[]) {
	const char* a="abc";
	//Combination2(test,strlen(test));
	//vector<char> vec;
	//Combination(test, vec);
	//int a[]={1,2,3,4};
	CombinationNumber(a,3);
	return 0;
}


