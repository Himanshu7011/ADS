#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINKED_LIST_SIZE 10
struct node {
	int number;
	struct node *next;
};

/* Insert a new element in the list */
struct node* insertStart(struct node *ptr, int num)
{
	/* Create a memory for new node */
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	memset(newNode, 0, sizeof(struct node));

	/* Fill in the data in newly created node */
	newNode->number = num;
	newNode->next = ptr;
	printf(" %d ", newNode->number);

	ptr = newNode;
	return newNode;
}

struct node* deleteNode(struct node *ptr)
{
	if(ptr == NULL) {
		printf("All nodes are deleted from the linked list... Returning\n");
		return ptr;
	}
	struct node *freeNode = ptr;
	printf(" %d ", ptr->number);
	ptr = (ptr)->next;
	free(freeNode);
	return ptr;
}

/* Print the elements of linked list */
void traverseNode(struct node *ptr)
{
	int i = 0;
	printf("LinkedList: = ");
	while(ptr) {
		printf("%d ", ptr->number);
		ptr = ptr->next;
	}
}

// main function.
int main()
{
	int i = 0, x = 100;
	struct node *head = NULL; /* Create head point to point to head of the linked list. */
	printf("Adding node: ");
	while(i++ < LINKED_LIST_SIZE) {
		head = insertStart(head, x);
		x = x - LINKED_LIST_SIZE;
	}
	printf("\n");

	traverseNode(head);
	printf("\nDeleting node: ");
	i = 0;
	while(i++ < LINKED_LIST_SIZE) {
		head = deleteNode(head);
	}
	printf("\n");
}


