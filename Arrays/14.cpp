// N-bonacci number. Print first m N-bonacci number.


#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n;
    cin>>m;
    int arr[m];
    for(int i=0;i<n-1;i++)
        arr[i] = 0;
    arr[n-1] = 1;
    int curr_sum = 0;
    for(int i=0;i<n;i++)
        curr_sum += arr[i];
    arr[n] = curr_sum; 
    for(int i=n+1;i<m;i++){
        curr_sum = curr_sum + arr[i-1] - arr[i-n-1];
        arr[i] = curr_sum;
    }
    for(int i=0;i<m;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}
