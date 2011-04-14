using System;

namespace ReverseSentence
{
	class MainClass
	{
	   const char EMPTY_CHAR=' ';
		
		public static void Main (string[] args)
		{
			string testString=@"I am just a test!";
			char[] testCharArray=testString.ToCharArray();
			ReveseSentence(testCharArray);
			Console.ReadLine();
		}
		
		private static void ReveseSentence(char[] charArray)
		{
			if(charArray.Length<=1)
				return;
			//Revese String firstly
			Console.Write("Befor revese String --");
			Console.WriteLine(charArray);
			ReverseString(charArray,0, charArray.Length-1);
			Console.Write("After reverse string --");
			Console.WriteLine(charArray);
			int endIndex=0;
			int startIndex=0;
			while(endIndex<charArray.Length)
			{
				startIndex=FindFirstNonEmptyChar(charArray, endIndex);
				endIndex=FindFirstEmptyChar(charArray, startIndex);
				ReverseString(charArray, startIndex, endIndex-1);
			}
			Console.Write("After reverse setence --");
			Console.WriteLine(charArray);
		}
		
		private static int FindFirstNonEmptyChar(char[] charArray, int startIndex)
		{
			int arrayLength=charArray.Length;
			int index=startIndex;
			while(index<arrayLength&&charArray[index]==EMPTY_CHAR)
				index++;
			return index;
		}
		
			
		private static int FindFirstEmptyChar(char[] charArray, int startIndex)
		{
			int arrayLength=charArray.Length;
			int index=startIndex;
			while(index<arrayLength&&charArray[index]!=EMPTY_CHAR)
				index++;
			return index;
		}
		
		private static void ReverseString(char[] charArray, int startIndex, int endIndex)
		{
			
			int i=startIndex;
			int j=endIndex;
			while(i<j)
			{
				char temp=charArray[i];
				charArray[i]=charArray[j];
				charArray[j]=temp;
				i++;
				j--;
			}
		}
		
	}
}

