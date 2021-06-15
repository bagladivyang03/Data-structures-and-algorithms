#include<iostream>
using namespace std;

int isSubsets(int arr[],int n, int sum){
    if(n==0)
        return sum==0 ? 1 : 0;
    return isSubsets(arr,n-1,sum) + isSubsets(arr,n-1,sum-arr[n-1]);
}

int main()
{
    int arr[] = {10,12,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 25;
    if (isSubsets(arr,n,sum) == 1)
        cout<<"Subsets found"<<endl;
    else    
        cout<<"Subsets not found"<<endl;
}