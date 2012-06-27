#include <stdio.h>
#include <stdlib.h>


typedef  enum{false,true} bool;


int find_max(int distance[], int freq[]) {
    int max_i = -1;
    int max = -1;
    for (char c = 'a'; c <= 'z'; c++) {
        if (distance[c]<=0 && freq[c]>max) {
            max = freq[c];
            max_i = c;
        }
    }
    return max_i;
}

void create(char* str, int d, char ans[]) {
    int n = strlen(str);
    int freq[256] = {0};
    
    for (int i = 0; i < n; i++)
        freq[str[i]]++;
    
    int distance[256] = {0};
    for (int i = 0; i < n; i++) {
        
            int j = find_max(distance, freq);
            if (j == -1) {
                printf("Error!\n") ;
                return;
            }
        
        ans[i] = j;
        freq[j]--;
        
        distance[j] = d;
        
        for (int i = 0; i < 256; i++)
            distance[i]--;
        }
    ans[n] = '\0';
}


int main(int argc, char *argv[]) {
	 // insert code here...
	    char a[]="abb";
	    int d=2;
	    char answer[]={0};
	    
	    create(a,d,answer);
	    return 0;

}