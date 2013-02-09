int getHighOrders(int number){
        int step=10;
		while(number/step>=10){
			step=step*10;
		}
		return step;
	}
 
	bool isPalindromePositiveNumber(int number){
		int highOrder=getHighOrders(number);
		int lowerOrder=10;
		while(lowerOrder<=highOrder && number>0){
			int lowerDigit=number % lowerOrder;
			int highDigit= number/highOrder;
			if(lowerDigit!=highDigit){
				return false;
			}
			number=number-highOrder*highDigit;
			number=number/lowerOrder;
			highOrder=highOrder/100;
		}
		return true;
	}
 
class Solution {
public:
    bool isPalindrome(int number) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(number<0) 
            return false;
        
        if(number>0 && number<10)
    		return true;
 
		return isPalindromePositiveNumber(number);
    }
};