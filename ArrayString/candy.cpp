    #include <vector>
    #include <iostream>
    #include <cassert>
    #include <climits>

    using namespace std;



    int candy(vector<int> &ratings) {

        int sum=0;
        int prevRating=INT_MIN;
        int currentCandy=0;
        int startCandy=0;
        int prevCandy=0;
        int size=ratings.size();
        vector<int> candies(size);
        for(int i=0; i<size; i++){
            int rating=ratings[i];
            if(rating>prevRating){
                currentCandy++;
                candies[i]=currentCandy;
            }
            else if(rating<=prevRating){
                candies[i]=1;
                int j=i-1;
                while(j>=0 && ratings[j]>ratings[j+1] && candies[j]<=candies[j+1] ){
                    candies[j]++;
                    j--;
                }
            }
            prevRating=rating;
        }
        for (int i = 0; i < size; ++i){
            sum +=candies[i];
        }
        return sum;
    }


    int main(int argc, char const *argv[])
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(4);
        v.push_back(4);
        v.push_back(3);


        assert(9==candy(v));

        v.clear();
        v.push_back(1);
        v.push_back(1);


        assert(2==candy(v));
    }