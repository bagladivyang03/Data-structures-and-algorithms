// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        map<int, int> m;
        int ans1, ans2;
        // int ans[] = {0,0}; 
        for(int i=1;i<=n;i++)
            m[i] = 0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        for(auto x: m){
            // cout<<x.second<<" ";
            if(x.second == 0)
              ans2 = x.first;
            else if(x.second == 2)
                ans1 = x.first;
        }
        
        // for(int i=0;i<n;i++){
        //     if(arr[abs(arr[i]) - 1]>0)
        //         arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        //     else
        //         ans1 = abs(arr[i]);
        
        // }
        // for(int i=0;i<n;i++){
        //     if(arr[i] > 0)
        //         ans2 = i+1;
        // }
        // int temp[n+1];
        // for(int i=1;i<=n;i++){
        //     temp[i] = 0;
        // }
        // for(int i=0;i<n;i++){
        //     if(temp[arr[i]]==0)
        //         temp[arr[i]] = 1;
        //     else if(temp[arr[i]]==1)
        //         ans1 = arr[i];
        // }
        // for(int i=1;i<=n;i++){
        //     if(temp[i]==0){
        //         ans2 = i;
        //         break;
        //     }
        // }
        arr[1] = ans2;
        arr[0] = ans1;
        return arr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends