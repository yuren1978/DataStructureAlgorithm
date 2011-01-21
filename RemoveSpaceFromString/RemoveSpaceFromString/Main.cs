using System;
 using System.Text;

namespace RemoveSpaceFromString
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string test="I am a just test";
			string removedString= RemoveSpace(test);
			Console.WriteLine(removedString);
		}
		
		
		private static string RemoveSpace(string input)
		{
			StringBuilder sb=new StringBuilder(); 
			int length=input.Length;
			for(int index=0; index<length; index++)
			{
				if(input[index]!=' ')
				{
					sb.Append(input[index]);
				}
			}
			return sb.ToString();
		}
	}
}

