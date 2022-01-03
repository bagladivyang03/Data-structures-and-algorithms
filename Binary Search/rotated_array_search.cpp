// Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int binarySearch(int A[],int l, int h, int key){
            if (h < l)
                return -1;
            int m = (l+h)/2;
            if(A[m]==key)
                return m;
            else if(A[m] > key)
                return binarySearch(A,l ,m-1, key);
            return binarySearch(A,m+1,h, key);
    }
    int findPivot(int A[],int l, int h){
        if(h<l)
            return -1;
        if(l==h)
            return l;
        int m = (l+h)/2;
        if(m<h && A[m] > A[m+1])
            return m;
        if(m>l && A[m] < A[m-1])
            return m-1;
        if(A[l] >= A[m])
            return findPivot(A,l,m-1);
        return findPivot(A,m+1,h);
    }
    int search(int A[], int l, int h, int key){
        int pivot = findPivot(A,0,h);
        if(pivot == -1)
            return binarySearch(A,0,h,key);
        if(A[pivot] == key)
            return pivot;
        if(A[0]<=key)
            return binarySearch(A,0,pivot-1,key);
        return binarySearch(A,pivot+1,h,key);
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends