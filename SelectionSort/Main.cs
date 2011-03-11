using System;


namespace SelectionSort
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine ("Hello World!");
			int[] a={2,5,3,1,8};
			SelectSorting(a);
			foreach (int item in a) {
				Console.WriteLine(item);
			}
			
		}
	
		public static void SelectSorting(int[] elements)
		{
			int length=elements.Length;
			for(int index=0; index<length-1; index++)
			{
				int minElement=elements[index];
				int minIndex=index;
				//find the minimum element to the right.
				for (int j = index+1; j < length; j++) {
					if(elements[j]<minElement)
					{
						minElement=elements[j];
						minIndex=j;
					}
				}
				
				//exchange element
				int temp=elements[minIndex];
				elements[minIndex]=elements[index];
				elements[index]=temp;
				
			}
		}
	}
}

