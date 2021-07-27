// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isSubSetSum(int n, int arr[], int s){
        int t[n+1][s+1];
        for(int i=0;i<n+1;i++)
            t[i][0] = 1;
        for(int j=1;j<s+1;j++)
            t[0][j] = 0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<s+1;j++){
                if(arr[i-1]<=j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                if(arr[i-1] > j)
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][s];
    }
    int equalPartition(int N, int arr[])
    {
        int s = 0;
        for(int i=0;i<N;i++)
            s += arr[i];
        // cout<<s;
        if(s%2!=0)
            return 0;
        return isSubSetSum(N, arr, s/2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends