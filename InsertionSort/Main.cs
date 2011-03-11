using System;

namespace InsertionSort
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			//define an array
			int[] a={4,3, 2, 1, 5};
			Sort(a); 
			foreach (int item in a) {
				Console.WriteLine(item);
			}
		}
		
		public static void  Sort(int[] array)
		{
			int length=array.Length;
			int toBeSortedElementIndex=1;
			while (toBeSortedElementIndex<length) {
				int elementToCheck=array[toBeSortedElementIndex];
				int i=toBeSortedElementIndex-1;
				while ( i>=0 && array[i]>elementToCheck ) {
					array[i+1]=array[i];
					i--;
				}
				array[i+1]=elementToCheck;
				toBeSortedElementIndex++;
			}
		}
	}
}


// 0,1,2,3
// 2,3,5,4
// 2,3, ,5
