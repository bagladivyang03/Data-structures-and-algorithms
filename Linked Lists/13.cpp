// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head){
        Node *curr =head, *prev =NULL;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next= prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head = reverse(head);
        Node *res = head;
        Node *temp = NULL, *prev = NULL;
        int carry = 1, sum;
        while(head!=NULL){
            sum = carry + head->data;
            carry = (sum>=10) ? 1 : 0;
            sum = sum % 10;
            head->data = sum;
            temp = head;
            head = head->next;
        }
        if(carry > 0)
            temp->next = new Node(carry);
        return reverse(res);
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends