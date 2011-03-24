using System;

namespace StringImmutable
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			char[] test="Hello World!".ToCharArray();
			Console.WriteLine(test);
			test[0]='a';
			Console.WriteLine(test);
		}
	}
}

