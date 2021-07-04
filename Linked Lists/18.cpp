// Sort the given Linked List using quicksort. which takes O(n^2) time in worst case and O(nLogn) in average and best cases, otherwise you may get TLE.

// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

node *getTail(node *curr){
    while(curr!=NULL && curr->next!=NULL)
        curr = curr->next;
    return curr;
}

node *partition(node* head, node* end, node** newhead,node** newend){
    node *pivot = end;
    node *prev = NULL, *curr = head, *tail = pivot;
    while(curr!=pivot){
        if(curr->data < pivot->data){
            if(*newhead==NULL)
                *newhead = curr;
            prev = curr;
            curr = curr->next;
        }
        else{
            if(prev)
                prev->next = curr->next;
            node *temp =curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    if(*newhead == NULL)
        *newhead = pivot;
    *newend = tail;
    return pivot;
}
node *quickSortRecur(node *head, node* end){
    if(!head || head==end)
        return head;
    node *newhead = NULL, *newend = NULL;
    node *pivot = partition(head,end,&newhead,&newend);
    if(newhead!=pivot){
        node *temp = newhead;
        while(temp->next!=pivot)
            temp = temp->next;
        temp->next = NULL;
        newhead = quickSortRecur(newhead,temp);
        temp = getTail(newhead);
        temp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next,newend);
    return newhead;
}
void quickSort(struct node **headRef) {
    *headRef = quickSortRecur(*headRef,getTail(*headRef));
    return;
}e