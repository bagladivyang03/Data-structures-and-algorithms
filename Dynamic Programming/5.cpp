// Given two strings. The task is to find the length of the longest common substring.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        int res = 0;
        for(int i=0;i<n+1;i++)
            dp[i][0] = 0;
        for(int i=0;i<m+1;i++)
            dp[0][i] = 0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res,dp[i][j]);
                }
                    
                else
                    dp[i][j] = 0;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends