#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

void numDistinct(string S, string T, int sStart, int tIndex, int sSize, int tSize,  int& count) {
     // Start typing your C/C++ solution below
     // DO NOT write int main() function

    if(sStart==sSize && tIndex<tSize)
     {
          return;
 	 }

 	 if (tIndex==tSize && sStart<=sSize )
 	 {//last charactor of 
 	 	count++;
 	 	return;
 	 }
    
	char tChar=T[tIndex];
	for (int i = sStart; i < sSize; ++i)
	{
		if(tChar==S[i]){
			numDistinct(S,T,i+1, tIndex+1, sSize, tSize,  count);
		}
	}	
 }



 int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count=0;
        int tSize=T.size();
        int sSize=S.size();
    	numDistinct(S, T, 0, 0, sSize, tSize, count);
    	return count;
    }

 
int main(int argc, char *argv[]) {
	cout<< numDistinct("ccc","cc")<<endl;
}