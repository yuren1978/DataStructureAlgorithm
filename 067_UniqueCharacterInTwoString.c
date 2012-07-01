#include <stdio.h>

//两个字符串，求出unique characters，即只出现在一个string中的cha（array[26]，用0-3标记）
int main(int argc, char *argv[]) {
	const char* firstString="abcdefhjkm";
	const char* secondString="defghkft";
	int a[26]={0};
	for (int index=0; index<strlen(firstString);index++) {
		a[firstString[index]-'a']++; 
	}
	for (int index=0; index<strlen(secondString);index++) {
		a[secondString[index]-'a']++; 
	}
	for(int index=0; index<26; index++){
		if(a[index]==1){//only appear once
			printf("%c\t",'a'+index);		
		}
	}
}