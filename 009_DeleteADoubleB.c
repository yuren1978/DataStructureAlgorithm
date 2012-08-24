//http://www.mitbbs.com/article_t1/JobHunting/32113349_0_2.html
//处理一个字符串，删除里面所有的A，double所有的B 例子，输入 CAABD, 输出是CBBD
//要求in space , O (1), no extra memory cost,因为字符串处理变长的空间不算, facebook
#include <stdio.h>
#define MAX_S_LENGTH 1024

void removeCharacter(char* s, char compareChar){
	int i,j;
	j=0;
	for (i = 0; s[i] != '\0'; i++) {
		if(s[i]!=compareChar){
			s[j]=s[i];
			j++;
		}
	}
	s[j]='\0';
}

void remove_a_double_b(char *s) {
	
}

int main(int argc, char *argv[]) {
	char s[MAX_S_LENGTH]="ACDEBBAEF";
	removeCharacter(s,'A');
	//remove_a_double_b(s);
	printf("%s\n", s);
}