using System;
using System.Text;

namespace ReverseString
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string helloWorld="Hello World!";
			Console.WriteLine (helloWorld);
			Console.WriteLine(ReverseString(helloWorld) );
			Console.WriteLine(RecursiveReverseString(helloWorld) );
			//Console.WriteLine(ReverseStringFromMiddle(helloWorld) );
		}
		
		public static  string ReverseString(string inputString)
		{
			int stringLength=inputString.Length;
			StringBuilder sb=new StringBuilder();
			for (int i = stringLength-1; i >=0; i--) {
				sb.Append(inputString[i]);
			}
			return sb.ToString();
		}
		
		
		public static  string RecursiveReverseString(string inputString)
		{
			int stringLength=inputString.Length;
			if(stringLength<=1) return inputString;
			//call recursively
			string leftString=inputString.Substring(0, stringLength/2);
			string rightString=inputString.Substring( stringLength/2);
			return RecursiveReverseString(rightString)+RecursiveReverseString(leftString);
		}
		
		
		
//		public static string ReverseStringFromMiddle(string inputString)
//		{
//			int stringLength=inputString.Length;
//			int halfLength=stringLength/2;
//			for(int index=0; index<halfLength; index++)
//			{
//				char temp=inputString[index];
//				inputString[index]=inputString[stringLength-index];
//				inputString[stringLength-index]=temp;
//			}
//			return inputString;
//		}
	}
}

