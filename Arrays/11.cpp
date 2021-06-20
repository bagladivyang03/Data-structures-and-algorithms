// Given an array a[] of N integers, the task is to find the length of the longest Alternating Even Odd subarray present in the array. 

#include<bits/stdc++.h>
using namespace std;

int longestevenodd(int arr[],int n){
    int res = 1, curr= 1;
    for(int i=1;i<n;i++){
        if((arr[i]%2 == 0 && arr[i-1]%2 != 0) || (arr[i]%2 != 0 && arr[i-1]%2==0)){
            curr++;
            res = max(res,curr);
        }
        else    
            curr = 1;
    }
    return res;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<longestevenodd(arr,n);
    cout<<endl;
}