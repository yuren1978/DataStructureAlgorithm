#include <vector>
using namespace std;

int computeCointCount(const vector<int>& coins, vector<int>& cointCount, int currentAmount){
        int currentCount=-1;
        for(int coinAmount : coins){
            if(currentAmount==coinAmount){
                currentCount=1;
                break;
            }
            else{
                if(cointCount[currentAmount-coinAmount-1]>0){
                    if(currentCount>0)
                        currentCount=min(cointCount[currentAmount-coinAmount-1]+1,currentCount);
                    else
                        currentCount=cointCount[currentAmount-coinAmount-1]+1;
                }
            }
        }
        return currentCount;
}
    

int coinChange(vector<int>& coins, int amount) {
    vector<int> cointCount(amount, -1);
    for(int i=0; i<amount; i++){
        cointCount[i]=computeCointCount(coins, cointCount,i+1);
    }
    return cointCount[amount-1];
}



int main(int argc, char const *argv[])
{
    vector<int> coins {1,2,5};
    int cointChange=coinChange(coins, 11);
    return 0;
}
