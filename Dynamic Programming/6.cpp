// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        string r = S;
        reverse(r.begin(),r.end());
        int len = S.length();
        int dp[len+1][len+1];
        for(int i=0;i<len+1;i++){
           dp[i][0] = 0;
           dp[0][i] = 0;
        }
        for(int i=1;i<len+1;i++){
            for(int j=1;j<len+1;j++){
                if(S[i-1]==r[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return len-dp[len][len];
    } 
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
return 0;
}  // } Driver Code Ends