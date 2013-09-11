using System;
using System.Collections.Generic;

class Sqrt
{
	
	static bool Equal(double a, double b){
		return Math.Abs(a-b)<0.000001;
	}
	
	static double GetSqrt(double number){
		if(number<0)
			return -1;
		if(number==0)
			return 0;
		if (number==1) 
			return 1;
			
		
		double start=0;
		double end=number<1?1:number;
		while (!Equal(end,start)) {
			double middle=(start+end)/2;
			if(Equal(middle*middle, number)){
				return middle;
			}
			else if (middle*middle>number) {
				end=middle;
			}
			else {
				start=middle;
			}
		}
		return end;				
	}

	static void Main(){
		Console.WriteLine("Get Sqrt");
		Console.WriteLine(GetSqrt(25));
		Console.WriteLine(GetSqrt(0.25));
	}	
}