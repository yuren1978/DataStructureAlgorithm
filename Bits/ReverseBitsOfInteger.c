//http://www.leetcode.com/2011/08/reverse-bits.html
//https://www.evernote.com/Home.action#st=p&n=295b9b05-0e02-4014-8a15-5d593a7b7e13

#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned int uint;

uint swapBit(uint x, uint i, uint j){
	uint lo=(x>>i) & 1; //i bit
	uint hi=(x>>j) & 1 ; //j bit
	if(lo ^ hi){ //low not equal to high
		x^= (1U<<i) | (1U <<j);
	} 
	return x;
}

uint reverseBit(uint x){
	uint n=sizeof(x)*8;
	for (uint i = 0; i < n/2; ++i){
		x=swapBit(x, i, n-1-i);
	}
	return x;
}

int main(int argc, char *argv[]) {
	uint test=5;
	cout<<reverseBit(5)<<endl;
}