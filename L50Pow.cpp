#include <iostream>
#include <cassert>

using namespace std;

double positivePow(double x, int n){
	if(n==1)
		return x;
	
	
	double result=x;	
	int s=1;	
	do {
		result=result*result;
		s=s*2;
	}while ((s*2)<n) 
	
	
		
	return result;	
}


double pow(double x, int n){
	bool negative=false;
	if(n==0) return 1;
	if(n<0) negative=true;
	
	double result=negative? positivePow(x,-n):positivePow(x,n);
	
	return  negative? (1.0)/(result): result;
	
}

int main(int argc, char *argv[]) {
	
}