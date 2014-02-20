 int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 	int size=height.size();
 	int start=0;
 	int end=size-1;
 	int maxArea=0;
 	int height=0;
 	while(start<end){
 		if(height[start]<height[end]){
 			height=	height[start];
 			start++;
 		}
 		else{
			height=	height[end];
			end--;
 		}
 		int area=height*(end-start+1);
 		if(area>maxArea){
 			maxArea=area;
 		}
 	}	
    return maxArea;    
 }