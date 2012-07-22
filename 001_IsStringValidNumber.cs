//http://www.mitbbs.com/article_t/JobHunting/32161845.html
//http://stackoverflow.com/questions/237159/whats-the-best-way-to-check-to-see-if-a-string-represents-an-integer-in-java
//consider overflow too.
using System;
using System.Diagnostics;

class NumberClass{
	static bool IsValidInteger(string number){
		if(string.IsNullOrEmpty(number))
			return false;
		
		int i=0;
		if(number[i]=='-')
			i++;
		if(number.Length==1)
			return false;	
		
		for(; i<number.Length; i++){
			if(number[i]<'0' || number[i]>'9'){
				return false;
			}
		}	
		return true;	
	}
	
	
	static void Main(){
		Console.WriteLine("Test Valid Number");		Console.WriteLine(IsValidInteger("10"));
		Console.WriteLine(IsValidInteger("-10"));
		Console.WriteLine(IsValidInteger("a10"));
		Console.WriteLine("Finish Testing");
	}
}