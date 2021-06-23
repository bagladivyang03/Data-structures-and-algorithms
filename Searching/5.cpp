// Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
{
        int i = nums1.size();
        int j = nums2.size();
        int arr[i+j];
        int l = i+j;
        for(int k=0;k<i;k++)
            arr[k] = nums1[k];
        int a = 0;
        for(int k =i;k<l;k++)
            arr[k] = nums2[a++];
        sort(arr,arr+l);
        if(l % 2 == 0){
            int z = l / 2;
            double e = (double)arr[z];
            double q = (double)arr[z-1];
            double ans = (double)((e+q)/2);
            return ans;
        }
        else{
            int z = round(l / 2);
            return (double)arr[z];
        }
        return 0.0;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin>>array1[i];
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin>>array2[i];
        cout<<MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends