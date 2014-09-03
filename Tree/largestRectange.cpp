    #include <stack>
    #include <vector>
    #include <iostream>
    using namespace std;


    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> s;
        int size=height.size();
        int maxArea=0;
        for(int i=0; i<size; i++){
            if(s.empty()||height[i]>height[s.top()]){
                s.push(i);
            }
            else{
                int tmp=s.top();
                s.pop();
                maxArea=max(maxArea, height[tmp]*(s.empty()? i: i-s.top()-1 ));
                cout<<maxArea<<endl;
                i--;
            }
        }
        return maxArea;
    }

    int main(int argc, char const *argv[])
    {
        vector<int> a{1,2,3,4,5};
        int maxArea=largestRectangleArea(a);
        return 0;
    }