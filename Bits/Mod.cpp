#include<iostream>
using namespace std;

/*
首先ab 中可以设b=2t1+2t2+…+2tk
(二进制) 即将b转换为二进制表示
b&1就是判断b的二进制表示中第0位上的数是否为1,若为1,b&1=true,反之b&1=false 还不理解?进传送门
b&1也可以用来判断奇数和偶数,b&1=true时为奇数,反之b&1=false时为偶数
*/
//https://www.acwing.com/blog/content/2647/


int main()
{
    long long  a=3,b=9,p=7,res=1;
    while(b)
    {
        cout<< " a : "<<a<<" b: "<<b<<" p: "<<p <<" res: "<<res<<endl;
        
        if(b&1) 
            res=res*a%p;

        b>>=1;//b右移了一位后,a也需要更新
        a=a*a%p;
    }
    cout<< " Final Answer is:  "<< res%p <<endl;
}