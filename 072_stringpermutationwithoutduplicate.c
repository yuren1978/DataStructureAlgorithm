#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *str, int first, int second){
	char temp=str[first];
	str[first]=str[second];
	str[second]=temp;
}



//pre: str is not sorted and str can't be changed. We can use hash to do this.
void PermutationWithDuplicateHash(char *str, int position)
{
 	int HashTable[128] = {0};  //assume ASCII
    if (position == strlen(str)) {
        printf("%s\n", str);
        return;
    }
        
    for (int i = position; i<strlen(str) ; i++)
    {        
        if (HashTable[str[i]] > 0) continue;
        else{
            HashTable[str[i]] = 1;
        }
            
        swap(str,position, i);
        PermutationWithDuplicateHash(str,position+1);
        swap(str,i , position);
    }  
}

void permute(char *str, int position) {
  
     if (position == strlen(str)) {
        printf("%s\n", str);
        return;
    }
        
    for (int i = position; i<strlen(str) ; i++)
    {        
        swap(str,position, i);
        PermutationWithDuplicateHash(str,position+1);
        swap(str,i , position);
    }  
}

int main()
{
    char str[] = "aba";    
	printf("allow duplicate\n");
    permute(str,0);
    // If duplicated character is allowed, let's sort the string first.
    //sort(str);
    //PermutationWithDuplicate(str, 0)
    
    //method 2. Using Hashtable to make a judgement whether it's duplicated
   printf("do not allow duplicate\n");
    PermutationWithDuplicateHash(str, 0);
	return 0;
}