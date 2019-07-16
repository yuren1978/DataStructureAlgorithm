#include<vector>
using namespace std;

int getNextWarmerDays(const vector<int>& T, const vector<int>& days, int i){
        if(T[i+1]>T[i])
            return 1;
        int currentTemp=T[i];
        int length=T.size();
        int j=i+1;
        while(j<length && T[j]<=currentTemp && days[j]>0){
            j=j+days[j];
        }
        return (j<length && T[j]>currentTemp) ? (j-i) :0 ;
    }
    
    vector<int> dailyTemperatures(vector<int>& T) {
        int size=T.size();
        vector<int> days(size, 0);
        for(int i=size-2; i>=0; i++){
            days[i]=getNextWarmerDays(T, days, i);
        }
        return days;
    }


int main(int argc, char const *argv[])
{
    vector<int> temp{ 73,74,75,71,69,72,76,73 };
    dailyTemperatures(temp);
    return 0;
}
