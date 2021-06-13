// Given an array where all elements appear even number of times except two, print the two odd occurring elements. It may be assumed that the size of array is at-least two.

#include<bits/stdc++.h>
using namespace std;
void printOdds(int arr[],int n){
int res = 0;
for (int i=0;i<n;i++){
    res = res ^ arr[i];
}
int setbit = res & ~(res-1);

int ans1 = 0, ans2 = 0;
for(int i=0;i<n;i++){
    if(arr[i] & setbit)
        ans1 = ans1 ^ arr[i];
    else   
        ans2 = ans2 ^ arr[i];
}
cout<<ans1<<" "<<ans2<<endl;
}

int main(){
    int arr[] = {1,1,1,2,2,4,5,5,6,6};
    printOdds(arr,sizeof(arr)/sizeof(arr[0]));

}
