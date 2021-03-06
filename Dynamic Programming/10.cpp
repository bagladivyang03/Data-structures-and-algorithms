//Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       
        long long dp[m+1][n+1];
         for(int i=0;i<m+1;i++){
             dp[i][0]  = 1;
         }
         for(int j=1;j<n+1;j++){
             dp[0][j] = 0;
          }
        for(int i=1;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(S[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i][j-S[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends