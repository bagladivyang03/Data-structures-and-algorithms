// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> mp;
        int res = 0, prefix_sum = 0;
        for(int i=0;i<N;i++){
            prefix_sum += A[i];
            if(prefix_sum == K)
                res = i+1;
            if(mp.find(prefix_sum) == mp.end())
                mp.insert({prefix_sum,i});
            if(mp.find(prefix_sum-K) != mp.end())
                res = max(res, i-mp[prefix_sum-K]);
        }
        return res;
    } 
};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends