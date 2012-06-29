#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	char src[] = "helo b";
	  int len = 0, spaces = 0;
	  /* Scan through src counting spaces and length at the same time */
	  while (src[len]) {
	    if (src[len] == ' ')
	      ++spaces;
	    ++len;
	  }
	  /* Figure out how much space the new string needs (including 0-term) and allocate it */
	  int newLen = len + spaces*2 + 1;
	  char * dst = malloc(newLen);
	  /* Scan through src and either copy chars or insert %20 in dst */
	  int srcIndex=0,dstIndex=0;
	  while (src[srcIndex]) {
	    if (src[srcIndex] == ' ') {
	      dst[dstIndex++]='%';
	      dst[dstIndex++]='2';
	      dst[dstIndex++]='0';
	      ++srcIndex;
	    } else {
	      dst[dstIndex++] = src[srcIndex++];
	    }
	  }
	  dst[dstIndex] = '\0';
	  /* Print the result */
	  printf("New string: '%s'\n", dst);
	  /* And clean up */
	  free(dst);
	  return 0;
}