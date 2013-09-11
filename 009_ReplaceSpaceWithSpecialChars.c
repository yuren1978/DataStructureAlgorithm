#include <stdio.h>
#include <stdlib.h>

//Method1 :Create a new string
//Method2 :Use an existing string  

void ReplaceWithNewString(const char* src, char* dst){
}

int main(int argc, char *argv[]) {
	  char src[] = "helo b";	
	  ReplaceWithNewString(src,dst);		 
	  /* And clean up */
	  free(dst);
	  return 0;
}