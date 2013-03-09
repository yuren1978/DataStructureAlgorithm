
public int divide(int dividend, int divisor) {
    long dividend_long=dividend;
    long divisor_long=divisor;
    boolean isNegative=false;
   
    if(dividend_long<0)
    {
        isNegative=true;
        dividend_long=-dividend_long;
    }
   
    if(divisor_long<0)
    {
        isNegative=!isNegative;
        divisor_long=-divisor_long;
    }
   
    int quotient=0;       
    while(dividend_long>=divisor_long)
    {
        long sum=divisor_long;
        int digit=1;
        while((sum+sum)<=dividend_long)
        {
            sum+=sum;
            digit<<=1;
        }
        quotient+=digit;
        dividend_long-=sum;
    }
   
    if(isNegative)
        quotient=-quotient;
   
    return quotient; 
}

class L029DivideInteger {
	public static void main(String[] args) {
	}
}