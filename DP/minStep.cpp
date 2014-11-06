    #include <iostream>
    #include <vector>

    using namespace std;

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
        int A[]={1,2,1,1,1};
        int n=sizeof(A)/sizeof(*A);
        int step=jump(A, n);
        cout<<step;
        return 0;
    }