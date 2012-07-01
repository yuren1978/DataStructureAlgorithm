using System;
using System.Collections.Generic;

namespace SumOfTwo
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			//http://www.ihas1337code.com/2010/12/two-sum-problem.html
			//Given an array of integers, find two numbers such that they add up to a specific target number.
			int[] a={3,2,1,8,7,9};
			int sum=9;
			int index1=-1, index2=-1;
			GetIndexForUnsortedArray(a, sum, ref index1, ref index2);
			Console.WriteLine("First index is " + index1 + " and Second index is "+index2);
			
		}
		
		private static bool GetIndexForUnsortedArray(int[] array, int sum, ref int index1, ref int index2)
		{
			bool found=false;
			Dictionary<int,int> hashTable=new Dictionary<int, int>();
			for (int i = 0; i < array.Length; i++) 
			{
				if(hashTable.ContainsKey(sum-array[i]))
				{
					index1=i;
					index2=hashTable[sum-array[i]];
					found=true;
					break;
				}
				else 
				{
					hashTable.Add(array[i], i);
				}
			}
			return found;
		}
		
	}
}

