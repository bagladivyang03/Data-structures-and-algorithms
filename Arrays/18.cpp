// Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void reverse(vector<int> &arr, int l, int h){
        while(l<=h){
            swap(arr[l],arr[h]);
            l++;
            h--;
        }
    }
    vector<int> nextPermutation(int N, vector<int> arr){
        if(N==0 || arr.size() <= 1) return arr;
        int i = arr.size() - 2;
        while(i>=0 && arr[i] >= arr[i+1])i--;
        if(i>=0){
            int j = arr.size()-1;
            while(arr[j]<=arr[i]) j--;
            swap(arr[i],arr[j]);
        }
        reverse(arr,i+1,arr.size()-1);
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends