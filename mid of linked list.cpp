#include<bits/stdc++.h> 
using namespace std; 

class Node 
{
    public:
	int data; 
    Node* next; 
}; 

void printMiddle(Node *head) 
{ 
     Node *slow_ptr = head; 
	 Node *fast_ptr = head; 

	if (head!=NULL) 
	{ 
		while (fast_ptr != NULL && fast_ptr->next != NULL) 
		{ 
			fast_ptr = fast_ptr->next->next; 
			slow_ptr = slow_ptr->next; 
		} 
		printf("The middle element is [%d]\n\n", slow_ptr->data); 
	} 
} 

void push( Node*head_ref, int new_data) 
{ 

	Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->next = head_ref; 
    head_ref= new_node; 
} 

void printList(Node *ptr) 
{ 
	while (ptr != NULL) 
	{ 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
} 

//Driver Code 
int main() 
{ 
    Node* head = NULL; 
	for (int i=5; i>0; i--) 
	{ 
		push(head, i); 
		printList(head); 
		printMiddle(head); 
	} 
	return 0; 
} 
