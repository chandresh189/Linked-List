// Program for converting singly linked list 
// into circular linked list. 
#include <bits/stdc++.h> 
#include<conio.h>
#include<stdio.h>
using namespace std;

/* Linked list node */
class node
{ public:
	int data; 
	node* next; 
}; 

// Function that convert singly linked list 
// into circular linked list. 
 node* circular(node* head) 
{ 
	// declare a node variable start and 
	// assign head node into start node. 
	node* start = head; 

	// check that while head->next not equal 
	// to NULL then head points to next node. 
	while (head->next != NULL) 
		head = head->next; 
		
	// if head->next points to NULL then 
	// start assign to the head->next node. 
	head->next = start; 
	return start; 
} 

void push(node** head, int data) 
{ 
	// Allocate dynamic memory for newNode. 
	node* newNode = new node(); 

	// Assign the data into newNode. 
	newNode->data = data; 

	// newNode->next assign the address of 
	// head node. 
	newNode->next = (*head); 

	// newNode become the headNode. 
	(*head) = newNode; 
} 

// Function that display the elements of 
// circular linked list. 
void displayList(node* node) 
{ 
	node* start = node; 

	while (node->next != start) { 
		cout<<" "<<node->data; 
		node = node->next; 
	} 
	
	// Display the last node of circular 
	// linked list. 
	cout<<" "<<node->data; 
} 

// Drier program to test the functions 
int main() 
{ 
	// Start with empty list 
	node* head = NULL; 

	// Using push() function to construct 
	// singly linked list 
	// 17->22->13->14->15 
	push(&head, 15); 
	push(&head, 14); 
	push(&head, 13); 
	push(&head, 22); 
	push(&head, 17); 

	// Call the circular_list function that 
	// convert singly linked list to circular 
	// linked list. 
	circular(head); 

	printf("Display list: \n"); 
	displayList(head); 

	return 0; 
} 
