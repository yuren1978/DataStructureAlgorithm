using System;
using System.Linq;

namespace LinqPractice
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			 String[] world = { "Hello World", "Hello Mars" , "Hello Venus" };
        	var rightOne = from s in world where s.EndsWith("World") select s;
	        foreach(string planet in rightOne)
	            Console.WriteLine("{0}",planet);
			}
	}
}

