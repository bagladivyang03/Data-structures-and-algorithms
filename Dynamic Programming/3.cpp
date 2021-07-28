// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    vector<int> isSubset(int arr[],int n,int s){
       bool dp[n+1][s+1];
       vector<int> v;
       for(int i=0;i<n+1;i++)
            dp[i][0] = true;
       for(int j=1;j<s+1;j++)
            dp[0][j] = false;
       for(int i=1;i<n+1;i++){
           for(int j=0;j<s+1;j++){
               if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
               else
                    dp[i][j] = dp[i-1][j];
           }
       }
       for(int i=0;i<=s/2;i++){
           if(dp[n][i]==true)
             v.push_back(i);
       }
       return v;
    }
	int minDifference(int arr[], int n)  { 
	    int s = 0;
	    for(int i=0;i<n;i++)
	        s += arr[i];
	    vector<int> v = isSubset(arr,n,s);
	    int mi = INT_MAX;
	    for(int i=0;i<v.size();i++)
	        mi = min(mi,s-2*v[i]);
	   return mi;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends