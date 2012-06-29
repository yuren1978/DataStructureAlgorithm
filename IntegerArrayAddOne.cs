//http://www.mitbbs.com/article_t1/JobHunting/32157787_0_1.html

using System;
using System.Collections.Generic;


class IntegerArray {
	
	
	static int[] ArrayPlusOne(int[] inArray){
		if(inArray==null)
			return inArray;
		int length=inArray.Length;	 	
		int carry=1;
		for (int i=length-1;i>=0; i--) {
			int res=inArray[i]+carry;
			carry=res>9?1:0;
			inArray[i]=res%10;
		}
		if(carry==1){
			int[] outArray=new int[length+1];
			outArray[0]=1;
			for (int i=1; i<=length; i++) {
				outArray[i]=inArray[i-1];
			}
			return outArray;
		}
		else {
			return inArray;
		}
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