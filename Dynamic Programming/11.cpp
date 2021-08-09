// Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button. You are not allowed to press bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long dp[10][10000];
	int mat[4][3] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
	long long solver(int i, int j, int N){
	    if(N==1) return 1;
	    if(dp[mat[i][j]][N] != -1) return dp[mat[i][j]][N];
	    long long a = solver(i,j,N-1);
	    long long b=0,c=0,d=0,e=0;
	    if(j-1 >=0 && mat[i][j-1]!=-1 ) b = solver(i,j-1,N-1);
	    if(j+1<  3 && mat[i][j+1]!=-1) c = solver(i,j+1,N-1);
	    if(i-1>=0 && mat[i-1][j]!=-1) d = solver(i-1,j,N-1);
	    if(i+1<4 && mat[i+1][j]!=-1) e = solver(i+1,j,N-1);
	    return dp[mat[i][j]][N] = a+b+c+d+e;
	}
	long long getCount(int N)
	{
		dp[10][N+1];
		memset(dp,-1,sizeof(dp));
		long long ans = 0;
		for(int i=0;i<4;i++){
		    for(int j=0;j<3;j++){
		        if(mat[i][j]!=-1){
		            ans += solver(i,j,N);
		        }
		    }
		}
		return ans;
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends