//http://en.wikipedia.org/wiki/3SUM
//http://basicalgos.blogspot.com/2012/03/3sum.html
//http://webcache.googleusercontent.com/search?q=cache:RIFcvYMVyQcJ:www.leetcode.com/2010/04/finding-all-unique-triplets-that-sums.html+&cd=3&hl=en&ct=clnk&gl=us

using System;
using System.Collections.Generic;

class ThreeSum
{
	
	
	static List<List<int>> GetThreeSum(List<int> list){
	}
	
	static void Main()
	{
	
		Console.WriteLine("Three Sum");	
		int[] a={-1, 0, 1, 2, -1, -4};
		List<int> integerList=new List<int>(a);
		List<List<int>> threeSumList= GetThreeSum(integerList);
		int length=threeSumList.Count;
		for (int i=0; i<length; i++) {
			Console.Write(" List is :");
			List<int> zeroList=threeSumList[i];
			for (int j=0; j<zeroList.Count; j++) {
				Console.Write(zeroList[j]+"-");
			}
			Console.WriteLine();
		}
		
	}	
}