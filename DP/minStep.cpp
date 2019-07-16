    #include <iostream>
    #include <vector>
    #include <limits>

    using namespace std;


    int maxProfit(int k, vector<int>& prices) {
        int min_int = numeric_limits<int>::min();        
        vector<int> sell(k+1,min_int);
        vector<int> buy(k+1, min_int);

        if(k <=1 || prices.size() <= 1) return 0;
        sell[0]  = 0;
        for(int price: prices) {
            for(int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j-1]-price);
                sell[j] = max(sell[j], buy[j]+price);
            }
        }
        return sell[k];
    }

    int jump(int A[], int n) {
        vector<int> step(n,0);
        
        for(int i=1; i<n; i++){
            cout<<" i is "<<i<<endl;
            int minStep;
            for(int j=0; j<i; j++){
                if(j+A[j]>=i){
                    cout<<"j is "<<j<<endl;
                    minStep=step[j]+1;
                    break;
                }
            }
            cout<<i<<" - "<<minStep<<endl;
            step[i]=minStep;
        }

        for (int i = 0; i < n; ++i)
        {
            cout<<step[i]<<" "; 
        }
        cout<<endl;
        
        return step[n-1];
    }

    int main(int argc, char const *argv[])
    {
        // int A[]={1,2,1,1,1};
        // int n=sizeof(A)/sizeof(*A);
        // int step=jump(A, n);
        // cout<<step;
        vector<int> prices {1,2};
        int result=maxProfit(1, prices);
        return 0;
    }