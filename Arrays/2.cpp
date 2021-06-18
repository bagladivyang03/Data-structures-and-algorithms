// Given an array of elements. Your task is to find the second maximum element in the array.


// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
   public:
    int print2largest(int arr[], int arr_size)
    {
        int first, second;
    	first = second = INT_MIN;
    	if(arr_size < 2)
    	    return -1;
    	for(int i=0;i<arr_size;i++){
    	    if(arr[i] > first){
    	        second = first;
    	        first = arr[i];
    	    }
    	    else if(arr[i] > second  && arr[i] < first)
    	        second = arr[i];
    	}
    	if(second == INT_MIN)
    	    return -1;
    	 else
    	    return second;
    }

};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.print2largest(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}
  // } Driver Code Ends