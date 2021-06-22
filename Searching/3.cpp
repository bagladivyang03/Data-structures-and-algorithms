// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on. You are given a number N, you have to output the number of integers less than N in the sample space S.

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int countSquares(int N) {
        if(N==1 || N==0)
            return 0;
        int l = 1,h = N;
        int ans = -1;
        while(l <= h){
            int m = (l+h)/2;
            // int sq = m*m;
            if(m*m == N)
                return m-1;
            else if(m <= N/m){
                l = m + 1;
                ans = m;
            }
            else{
                h = m - 1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends