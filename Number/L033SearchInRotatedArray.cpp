class Solution {
public:
    bool search(int A[], int n, int key) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          int l = 0, r = n - 1;
        while (l <= r) {
            int m = (r + l)/2;
            if (A[m] == key) return true; //return m in Search in Rotated Array I
            if (A[l] < A[m]) { //left half is sorted
                if (A[l] <= key && key <= A[m])
                    r = m - 1;
                else
                    l = m + 1;
            } else if (A[l] > A[m]) { //right half is sorted
                if (A[m] <= key && key <= A[r])
                    l = m + 1;
                else
                    r = m - 1;
            } else l++;
        }
        return false;
    }
};