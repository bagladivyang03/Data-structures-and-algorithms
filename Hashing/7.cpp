// Given two binary arrays arr1[] and arr2[] of same size N. Find length of the longest common span [i, j] where j>=i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j]. 

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
        int temp[n];
        for(int i=0;i<n;i++)
            temp[i] = arr1[i]-arr2[i];
        unordered_map<int,int>mp;
        int res = 0, prefix_sum = 0;
        for(int i=0;i<n;i++){
            prefix_sum += temp[i];
            if(prefix_sum == 0)
                res = i+1;
            if(mp.find(prefix_sum)==mp.end())
                mp[prefix_sum] = i;
            if(mp.find(prefix_sum)!=mp.end())
                res = max(res,i-mp[prefix_sum]);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        bool arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.longestCommonSum(arr1, arr2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends