using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IsUnsingedIntegerPowerOfTwo
{
    class Program
    {
        static void Main(string[] args)
        {
            uint number1 = 1;
            Console.WriteLine("number1 is the powr of " + IsPowerOfTwo(number1));
        }

        public static bool IsPowerOfTwo(uint number)
        {
            return (number & (number - 1))==0;
        }
    }
}
