// Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

// { Driver Code Starts


#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	   int *lower = lower_bound(arr,arr+n,x);
	   if(*lower != x || (lower ==  arr+n))
	     return 0;
	   int *higher = upper_bound(lower,arr+n,x);
	   return (higher-lower);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends