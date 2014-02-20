 int largestRectangleArea(vector<int> &height) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    stack<int> s;
    height.push_back(0);
    int size=height.size();
    int sum=0;
    for (int i = 0; i < size; ++i){
    	if(s.empty()||height[i]>height[S.top()]){
    		s.push_back(i);	
    	}
    	else{
    		int tmp=s.top();
    		s.pop();
    		sum=max(sum, height[temp]*(s.empty()? i: i-s.top()-1 ));
    		i--;
    	}
    }
    return sum;       
}