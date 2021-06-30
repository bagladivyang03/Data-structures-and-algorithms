// Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

// Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// â€‹Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 


// { Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    int prec(char c) {
            if(c == '^')
                return 3;
            else if(c=='*' || c=='/')
                return 2;
            else if(c == '+' || c == '-')
                return 1;
            else
                return -2;
        }
    string infixToPostfix(string s)
    {
        stack<char> st;
        string res = "";
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c >= '0' && c <= '9'))
                res += c;
            else if(c=='(')
                st.push(c);
            else if(c==')') {
                while(st.top()!='('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                if(!st.empty() && prec(st.top()) >= prec(s[i])){
                    res += st.top();
                    st.pop();
                }
                    st.push(c);
            }
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};


// { Driver Code Starts.
//Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string exp;
        cin>>exp;
        Solution ob;
        cout<<ob.infixToPostfix(exp)<<endl;
    }
    return 0;
}
  // } Driver Code Ends