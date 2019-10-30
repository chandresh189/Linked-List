// C Program to delete occurrenc of key in linked list 

#include <stdio.h> 
#include <stdlib.h> 
#include<bits/stdc++.h> 
using namespace std; 

class Node 
{ 
     public:
     	
     int data; 
	 Node *next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

void deleteKey(Node **head_ref, int key) 
{ 

	Node* temp = *head_ref, *prev; 

	while (temp != NULL && temp->data == key) 
	{ 
		*head_ref = temp->next; // Changed head 
		free(temp);			 // free old head 
		temp = *head_ref;		 // Change Temp 
	} 

	// Delete occurrences other than head 
	while (temp != NULL) 
	{ 
		// Search for the key to be deleted, keep track of the 
		// previous node as we need to change 'prev->next' 
		while (temp != NULL && temp->data != key) 
		{ 
			prev = temp; 
			temp = temp->next; 
		} 

		// If key was not present in linked list 
		if (temp == NULL) return; 

		// Unlink the node from linked list 
		prev->next = temp->next; 

		free(temp); // Free memory 

		//Update Temp for next iteration of outer loop 
		temp = prev->next; 
	} 
} 

void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<" "<<node->data<<" "; 
		node = node->next; 
	} 
} 

int main() 
{ 
  Node* head = NULL; 

	push(&head, 7); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 8); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 2); 

	int key = 2; 

	puts("Created Linked List: "); 
	printList(head); 

	deleteKey(&head, key); 
	puts("\nLinked List after Deletion of 1: "); 

	printList(head); 
	return 0; 
}
