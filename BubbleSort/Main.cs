using System;

namespace BubbleSort
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			//Every loop, you need move the biggest element to the end of the list.
			//so, next loop, you can only compare the first couple of elements.
			int[] a={3,2,5,4,1};
			BubbleSortArray(a);
			for (int i = 0; i < a.Length; i++) {
				Console.Write(a[i]);
			}
			Console.ReadLine();
		}
		
		private static void BubbleSortArray(int[] a)
		{
			//http://www.algolist.net/Algorithms/Sorting/Bubble_sort
			//key: move the largest element to the end.
			bool swapped=true;
			int j=0;
			while(swapped)
			{//outer loop
				swapped=false;
				j++;
				for (int i = 0; i < a.Length-j; i++) {//inner loop
					if(a[i]>a[i+1])
					{
						int temp=a[i];
						a[i]=a[i+1];
						a[i+1]=temp;
						swapped=true;
					}
				}
			}			
		}
	}
}