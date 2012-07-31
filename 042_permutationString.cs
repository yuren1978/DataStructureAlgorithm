using System;
using System.Collections.Generic;

class PermutationString{
	
	
	static string Swap(string inputString, int index1, int index2){
		char[] inputArray=inputString.ToCharArray();
		char temp=inputArray[index1];
		inputArray[index1]=inputArray[index2];
		inputArray[index2]=temp;		
		string toReturn=string.Empty;
		foreach (char c in inputArray) {
			toReturn+=c;
		}
		return toReturn;
	}
	
	static void PermutateString(string inputString, int index){
		int length=inputString.Length;
		if(index==length-1){
			Console.WriteLine(inputString);
		}
		else {
			for (int i=index; i<length; i++) {
				inputString=Swap(inputString, index, i);
				PermutateString(inputString, index+1);
				inputString=Swap(inputString, i, index);
			}
		}
	}
	
		
	static void Main(){
		string inputString="abcd";
		PermutateString(inputString, 0);
	}
}