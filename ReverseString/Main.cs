using System;
using System.Text;

namespace ReverseString
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string helloWorld="Hello World!";
			Console.WriteLine("----- reverse string  ---------");
			Console.WriteLine (helloWorld);
			Console.WriteLine(ReverseString(helloWorld) );
			Console.WriteLine("----- reverse string recursive ---------");
			Console.WriteLine(RecursiveReverseString(helloWorld) );
			Console.WriteLine("----- reverse string in place ---------");
			char[] helloWorldCharArray=helloWorld.ToCharArray();
			Console.WriteLine(helloWorldCharArray);
			ReverseStringInPlace(helloWorldCharArray);
			Console.WriteLine(helloWorldCharArray);
			Console.WriteLine("----- reverse string xor ---------");
			helloWorldCharArray=helloWorld.ToCharArray();
			Console.WriteLine(helloWorldCharArray);
			ReverseStringInPlaceXor(helloWorldCharArray);
			Console.WriteLine(helloWorldCharArray);
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
		
		public static void ReverseStringInPlaceXor(char[] helloWorldCharArray)
		{
			int length=helloWorldCharArray.Length;
			for (int i = 0, j = length-1; i<j ;i++,j--) {
				helloWorldCharArray[i]^=helloWorldCharArray[j];
				helloWorldCharArray[j]^=helloWorldCharArray[i];
				helloWorldCharArray[i]^=helloWorldCharArray[j];
			}
		}
	}
}

