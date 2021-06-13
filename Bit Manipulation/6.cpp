// Given a string S find all possible substrings of the string in lexicographically-sorted order.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    int n = s.length();
		    string ans_str = "";
		    int powsize = pow(2,n);
		    for(int c=0;c<powsize;c++){
		        for(int i=0;i<n;i++){
		            if(c & (1<<i))
		                ans_str += s[i];
		              //  cout<<s[i];
		        }
		      //  cout<<endl;
		        if(ans_str.length()!=0)
		            ans.push_back(ans_str);
		        ans_str = "";
		        
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends