// Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends

int firstoccurence(int arr[],int n, int x){
    int l = 0, h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m] > x)
            h = m - 1;
        else if(arr[m] < x)
            l = m + 1;
        else{
            if(m==0 || arr[m-1]!=arr[m])
                return m;
            else
                h = m - 1;
        }
    }
    return -1;
}

int lastoccurence(int arr[],int n, int x){
    int l = 0, h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m] > x)
            h = m - 1;
        else if(arr[m] < x)
            l = m + 1;
        else{
            if(m==n-1 || arr[m]!=arr[m+1])
                return m;
            else
                l = m + 1;
        }
    }
    return -1;
}

vector<int> find(int arr[], int n , int x )
{
   vector<int> ans;
   ans.push_back(firstoccurence(arr,n,x));
   ans.push_back(lastoccurence(arr,n,x));
   return ans;
}