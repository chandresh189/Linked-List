// delete a node in a linked list 
// at a given position 

#include <stdio.h> 
#include <stdlib.h>
#include<bits/stdc++.h> 
using namespace std; 

class node 
{ 
    public:
	int data; 
	node *next; 
}; 

void push(node** head_ref, int new_data) 
{ 
	node* new_node = new node();
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

/* Given a reference (pointer to pointer) to the head of a list 
and a position, deletes the node at the given position */
void deleteNode(node **head_ref, int position) 
{ 
// If linked list is empty 
if (*head_ref == NULL) 
	return; 

// Store head node 
 node* temp = *head_ref; 

	// If head needs to be removed 
	if (position == 0) 
	{ 
		*head_ref = temp->next; // Change head 
		free(temp);			 // free old head 
		return; 
	} 

	// Find previous node of the node to be deleted 
	for (int i=0; temp!=NULL && i<position-1; i++) 
		temp = temp->next; 

	// If position is more than number of ndoes 
	if (temp == NULL || temp->next == NULL) 
		return; 

	// Node temp->next is the node to be deleted 
	// Store pointer to the next of node to be deleted 
	 node *next = temp->next->next; 

	// Unlink the node from linked list 
	free(temp->next); // Free memory 

	temp->next = next; // Unlink the deleted node from list 
} 

// This function prints contents of linked list starting from 
// the given node 
void printList(node *node) 
{ 
	while (node != NULL) 
	{ 
	cout<<" "<< node->data ; 
	node = node->next; 
	} 
} 


int main() 
{ 
	node* head = NULL; 

	push(&head, 7); 
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 8); 

	cout<<"Created Linked List: "; 
	printList(head); 
	
	deleteNode(&head, 4); 
	cout<<"\nLinked List after Deletion at position 4: "; 
	printList(head);
	 
	return 0; 
} 
