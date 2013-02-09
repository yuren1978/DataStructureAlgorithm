#include <iostream>
#include <cassert>
#include <climits>

using namespace std;

int atoi(const char *str){
	assert(NULL!=str);
	       // DO NOT write int main() function
	        long long result=0;
	    long long positiveMax=INT_MAX;
		long long negativeMax=positiveMax+1;
		bool negative;
		const char* p=str;
		while (' '==*p) {	//skip space	
			++p;
		}
		if('-'==*p){
			negative=true;
			++p;
		}
	    if('+'==*p){
	    	++p;
		}
		while ('\0'!=*p) {
			if(*p<'0'||*p>'9'){//out of range
				break;
			}
			else {
				int value=*p-'0';
				result=10*result+value;
				if(result>positiveMax){
					result=positiveMax;
	                break;
				}
	            if(negative && result> negativeMax){
	                result=negativeMax;
	                break;
	            }
			}
			++p;
		}
		cout<<result<<endl;
		cout<<negativeMax<<endl;
		return negative? -result: result;
}

int main(int argc, char *argv[]) {
	//assert(0==atoi(""));
	//assert(1==atoi("1"));
	//assert(123==atoi("123"));
	assert(-2147483648==atoi("-2147483648"));
}