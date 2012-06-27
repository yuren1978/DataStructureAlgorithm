//programming for an integer, find out all the prime factors whose product is the integer 
//itself, eg: 12 = 2*2*3 print out those factors in a list.
using System;

class PrintPrimeFactor{
	
	static void PrimeFactor(int n){
		Console.Write("Factor of "+n+" : ");
		int prime=2;
		while (n>1) {
			if(n%prime==0){
				n=n/prime;
				Console.Write(prime+" ");
			}
			else {
				prime++;
			}
		}
		Console.WriteLine();	
	}
		
	static void Main(){
		PrimeFactor(213);
	}
	
}