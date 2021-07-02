// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        Node *even = NULL;
        Node *odd = NULL;
        Node * e = NULL;
        Node *o =NULL;
        Node *curr = head;
        while(curr!=NULL){
            if(curr->data%2!=0){
                if(odd == NULL){
                    odd = curr;
                    o = curr;
                }
                else{
                    o->next = curr;
                    o = o->next;
                }
            }
            else{
                if(even == NULL){
                    even = curr;
                    e = curr;}
                else{
                    e->next = curr;
                    e = e->next;
                }
            }
            curr = curr->next;
        }
        if(e){
            e->next = odd;
            
        }
        if(o)
            o->next = NULL;
        if(even)
            return even;
        return odd;
    }
};

// { Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}
  // } Driver Code Ends