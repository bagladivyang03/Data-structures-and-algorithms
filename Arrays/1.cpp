// Find the index of largest no from given array.

#include<bits/stdc++.h>
using namespace std;

int getLargest(int arr[],int n){
int max = arr[0];
int index = 0;
for(int i=0;i<n;i++){
    if(arr[i] > max){
        max = arr[i];
        index = i;
    }
}
return index;
}

int main(){
    int arr[] = {1,7,9,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<getLargest(arr,n)<<"- Index of largest no from given array." <<endl;
}