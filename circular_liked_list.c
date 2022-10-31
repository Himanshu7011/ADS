#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINKED_LIST_SIZE 10

struct node {
	int data;
	struct node *next;
};

/* Insert a new element in the list */
void insertStart(struct node **head, struct node **rear, int num)
{
	/* Create a memory for new node */
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	memset(newNode, 0, sizeof(struct node));

	newNode->data = num;
	if(*head == NULL) {
		newNode->next = *head;
		*head = newNode;
		*rear = newNode;
	} else {
		newNode->next = *head;
		(*rear)->next = newNode;
		*rear = newNode;
	}
}

void deleteNode(struct node **ptr, struct node **rear)
{

	struct node *freeNode = *ptr;

	if(*ptr == NULL)
		return;
	if((*ptr)->next == *ptr) { /* To handle the case, when only last node is there in linked list to delete. */
		free(*ptr);
		return;
	}
	*ptr = (*ptr)->next;
	(*rear)->next = *ptr;
	free(freeNode);
	freeNode = NULL;
}

/* Print the elements of linked list */
void traverseNode(struct node *ptr)
{
	/* Fix the traverse code */
}

// main function.
int main()
{
        int i = 0, x = 100;
        struct node *head = NULL, *rear = NULL; /* Create head point to point to head of the linked list. */

	insertStart(&head, &rear, 20);
	insertStart(&head, &rear, 30);
	insertStart(&head, &rear, 40);
	insertStart(&head, &rear, 50);
	insertStart(&head, &rear, 60);
	insertStart(&head, &rear, 70);
	traverseNode(head);
	deleteNode(&head, &rear);
	deleteNode(&head, &rear);
	deleteNode(&head, &rear);
	deleteNode(&head, &rear);
	deleteNode(&head, &rear);
	deleteNode(&head, &rear);
	traverseNode(head);
}
