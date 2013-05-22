class Solution {
public:
    int getMin(int a, int b){
        return a<b? a:b;
    }

    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          if(n==0 || n==1) return 0;
        
    
        int minLeftIndex=n-1;
        int step=0;
        while(minLeftIndex>0){
            step++;
            for(int i=0; i<n; ++i){
                if(i+A[i] >=minLeftIndex){
                    minLeftIndex=i;
                    break;
                }
            }
        }
        return step;
    }
};