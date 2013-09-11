using System;


class FindPrimeNumber{
	static void PrintPrimeNumbers(int n){	
		bool[] a=new bool[n+1];
		for (int i=0; i<=n; i++) {
			a[i]=true;
		}
		//set the element at position 0 and 1.
		if(n>=0){
			a[0]=false;
			if(n>=1){
				a[1]=false;
			}
		}
		int squareRoot=(int)Math.Sqrt(n);
		//cross out the non-prime number
		for (int i=2; i<=squareRoot;i++) {
			if(a[i]){
				for (int j=i*i; j<=n; j+=i) {
					a[j]=false;
				}
			}
		}
		//print out the true element
		for (int i=0; i<=n; i++) {
			if (a[i]) {
				Console.Write(i+"-");
			}
		}
	}
	
	static void Main(){
		Console.WriteLine("Find Prime Numbers");
		PrintPrimeNumbers(48);
	}
}