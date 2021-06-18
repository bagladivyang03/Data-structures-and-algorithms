// Given an unsorted array arr[] of size N, rotate it by D elements (clockwise). 

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,d;
	    cin>>n>>d;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int temp[d];
	    for(int i=0;i<d;i++)
	        temp[i] = arr[i];
	   for(int i=d;i<n;i++)
	        arr[i-d] = arr[i];
	   for(int i=0;i<d;i++)
	        arr[n-d+i] = temp[i];
	   for(int i =0;i<n;i++)
	        cout<<arr[i]<<" ";
	   cout<<endl;
	}
	return 0;
}