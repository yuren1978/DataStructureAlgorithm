using System;

  
 public class DivideTwoInteger{
	
public static int NativeDivide(int dividend, int divisor){
	int quotient=0;
	while (dividend>divisor) {
		dividend-=divisor;
		quotient++;
	}
	return quotient;
}	
 
 public static int divide(int dividend, int divisor) 
    {
        if (divisor == 0)
            throw new ArithmeticException();

        long a = dividend;
        long b = divisor;
        
        bool neg = false;
        if (a < 0)
            neg = !neg;
        if (b < 0)
            neg = !neg;
        a=Math.Abs(a);
        b=Math.Abs(b);
        int c = 0;
        while (b << c <= a){
               c++;
        }            
        int ans = 0;
        while (c >= 0)
        {
            Console.WriteLine(" c: "+ c + " a: "+a);
            if (b << c <= a)
            {
                a -= b << c;
               Console.WriteLine(" c: "+ c + " a: "+a);
  
                ans |= 1 << c;
                Console.WriteLine(" ans :"+ans);
            }
            c--;
        }
        return neg ? -ans : ans;
    }

    static void Main(){
        int answer=divide(-100,3);
        Console.WriteLine(answer);
		 int answer2=NativeDivide(100,3);
		 Console.WriteLine(answer2);
    }
}

 