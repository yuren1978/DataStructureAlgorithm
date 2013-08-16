//http://www.mitbbs.com/article_t1/JobHunting/32157787_0_1.html

using System;
using System.Collections.Generic;


class IntegerArray {
	
	
	static int[] ArrayPlusOne(int[] inArray){
	}
	
	static void PrintNumber(int number){
		Console.Write(number);
	}
	
	static void Main(){
		Console.WriteLine("Add one to integer Array");
		int[] inArray={1,2,3,9,9,9};
		int [] outArray=ArrayPlusOne(inArray);
		int outLength=outArray.Length;
		Console.WriteLine("Output Array is : ");
		for (int i=0; i<outLength; i++) {
			Console.Write(outArray[i]);
		}
	}
}