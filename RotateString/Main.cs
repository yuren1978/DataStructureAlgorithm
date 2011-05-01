using System;
using System.Text;
using System.Diagnostics;

namespace RotateString
{
	class MainClass
	{
		//https://docs.google.com/document/d/1iEjnGl6DE_8zcfI304ZvGHYAGZdr01dUe_Y_hFb9Urs/edit?hl=en#

		public static void Main (string[] args)
		{
			Console.WriteLine("start compare");
			Console.WriteLine( "rotate a "+  RotatingString("a")+ " ");
			Console.WriteLine( "rotate ab "+  RotatingString("ab")+ " ");
			Console.WriteLine( "rotate abc "+  RotatingString("abc")+ " ");
			Console.WriteLine( "rotate abcde "+  RotatingString("aebdc")+ " ");
			Console.WriteLine( "rotate abcdefg "+  RotatingString("abcdefg")+ " ");
			Console.ReadLine();
		}
		
		public static string RotatingString(string inputString)
		{
			//rotate a string
			//rotate a string
			StringBuilder sb=new StringBuilder();
			int stringLength=inputString.Length;
			for (int i = 0,j=stringLength-1 ; i <= j; i++,j--) {
				sb.Append(inputString[i]);
				if(i<j)
					sb.Append(inputString[j]);
			}
			return sb.ToString();
		}
	}
}

