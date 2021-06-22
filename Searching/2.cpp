// Given a binary array sorted in increasing order, count the number of 1’s in it.

#include<bits/stdc++.h>
using namespace std;

int count1s(int arr[],int n)
{
    int l = 0, h = n-1;
    while(l<=h){
        // cout<<"1"<<endl;
        int m = (l+h)/2;
        if(arr[m] == 0)
            l = m + 1;
        else{
            if(m==0 || arr[m-1]==0 )
                return n-m;
            else
                h = m-1;
        }

    }
    return 0;
}

int main(){
    int arr[] = {0,0,1,1,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<count1s(arr,n)<<endl;
}
