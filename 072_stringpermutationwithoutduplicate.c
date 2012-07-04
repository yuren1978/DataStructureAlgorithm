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
    if (position == strlen(str)-1) {
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

void permute(char *string_start, char *p) {
  
  if (*(p+1) == '\0') { /* End of string - just print it */
    printf("%s\n", string_start);
  }
  else {
    char *swap;
    /* Go along the string, swapping each element in turn with p */
    for(swap = p; *swap; ++swap) {
      char tmp = *swap;
      *swap = *p;
      *p = tmp;
      permute(string_start, p+1);
      *p = *swap;
      *swap = tmp;
    }
  }
}

int main()
{
    char str[] = "aba";    
	printf("allow duplicate\n");
    permute(str,str);
    // If duplicated character is allowed, let's sort the string first.
    //sort(str);
    //PermutationWithDuplicate(str, 0)
    
    //method 2. Using Hashtable to make a judgement whether it's duplicated
   printf("do not allow duplicate\n");
    PermutationWithDuplicateHash(str, 0);
	return 0;
}