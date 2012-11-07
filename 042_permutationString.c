//http://newton.ex.ac.uk/teaching/jmr/recursion.html
//How do you permute a string (ie print out all the permutations of its letters)? Well, for a one-letter string we just print it out. For a two-letter string it's almost as easy, just print out the string and the then the string reversed (there are only two permutations).
//How do you permute a three-letter string? Well, the permuations are
//The first letter followed by the permutions of the second and third letters.
//The second letter followed by the permutions of the first and third letters.
//The third letter followed by the permutions of the first and second letters.
//So the algorithm is:
//Keep the first letter constant and do all the permutations of the second and third letters (printing out the entire string each time).
//Swap the original first and second letters of the string, and repeat step 1 for the new string.
//Swap the original first and third letters of the string, and repeat step 1 for the new string.
//General algorithm
//For an N-letter string it's a bit like:
//for (i=0; i < N; ++i)
//Swap letters 0 and i.
//Permute letters 1 to N-1, printing out the entire string each time.
//Notice the similary with mathematical proof by induction: if we know how to do it for the case N=1 and if knowing how to do it for any N allows us to do it for N+1 we can do it for all strictly positive N. The code looks like this:



#include <stdio.h>

/*
 * Permute a string from p to the end and print out each
 * permutation starting from string_start (which never changes)
 * Does not avoid duplicates
 */
void permute(char *string_start, char *p) {
  
  if (*(p+1) == '\0') { /* End of string - just print it */
    printf("%s\n", string_start);
  }
  else {
    char *swap;
    /* Go along the string, swapping each element in turn with p */
    for(swap = p; *swap; ++swap) {
	   //printf("swap before=%c\n", *swap);	
      char tmp = *swap;
      *swap = *p;
  		//printf("swap after=%c\n", *swap);	
      *p = tmp;

      permute(string_start, p+1);
		
		
      *p = *swap;
      *swap = tmp;
		//printf("swap end=%c\n", *swap);
    }
  }
}

int main() {
  char string[] = "abc";  
  permute(string, string);
  return 0;	
}