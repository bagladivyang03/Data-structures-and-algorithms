// Given a string S. The task is to print all permutations of a given string.

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void helperfun(vector<string> &ans, string S,int i){
	      if(i==S.length()){
	       // cout<<S<<endl;
	        ans.push_back(S);
	        return;
	    }
	      for(int j=i;j<S.length();j++){
	          swap(S[i],S[j]);
	          helperfun(ans,S,i+1);
	          swap(S[i],S[j]);
	      }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    helperfun(ans,S,0);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends