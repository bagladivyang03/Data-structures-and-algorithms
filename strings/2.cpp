// Given two strings A and B, find if A is a subsequence of B.


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        int n = A.length();
        int m = B.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(A[i]==B[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i==n;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends