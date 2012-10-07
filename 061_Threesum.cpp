class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<vector<int> >* solution=new set<vector<int> >();
        sort(num.begin(), num.end());
        int size=num.size();
        for(int i=0; i<size; i++){
            int firstElement=num[i];
            int secondIndex=i+1;
            int thirdIndex=size-1;
            while(secondIndex<thirdIndex){
                if(firstElement+num[secondIndex]+num[thirdIndex]==0){
                    vector<int> solutionElement;
                    solutionElement.push_back(firstElement);
                    solutionElement.push_back(num[secondIndex]);
                    solutionElement.push_back(num[thirdIndex]);
                    solution->insert(solutionElement);
                    secondIndex++;
                    thirdIndex--;
                }
                else if(firstElement+num[secondIndex]+num[thirdIndex]<0){
                    secondIndex++;
                }
                else {
                    thirdIndex--;
                }
            }          
        }
        return *(new vector<vector<int> > (solution->begin(),solution->end() ));
    }
};