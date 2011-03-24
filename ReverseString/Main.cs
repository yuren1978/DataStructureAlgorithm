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
			char[] helloWorldCharArray=helloWorld.ToCharArray();
			Console.WriteLine(helloWorldCharArray);
			ReverseStringInPlace(helloWorldCharArray);
			Console.WriteLine(helloWorldCharArray);
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
		
		public static void ReverseStringInPlace(char[] helloWorldCharArray)
		{
			int length=helloWorldCharArray.Length;
			for(int i=0,j=length-1; i<j; i++,j--)
			{
				char temp=helloWorldCharArray[i];
				helloWorldCharArray[i]=helloWorldCharArray[j];
				helloWorldCharArray[j]=temp;
			}
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

