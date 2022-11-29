#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int number;
	struct node *next;
};

/* Insert a new element in the list */
void insertStart(struct node **ptr, int num)
{
	/* Create a memory for new node */
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	memset(newNode, 0, sizeof(struct node));

	/* Fill in the data in newly created node */
	newNode->number = num;
	newNode->next = *ptr;

	*ptr = newNode;
}

/* Print the elements of linked list */
void traverseNode(struct node *ptr)
{
	printf("\n");
	while(ptr) {
		printf("| %d | --> ", ptr->number);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void removeDuplicateElements(struct node **hptr) {
	
	struct node *front = *hptr;	
	struct node *back = *hptr;

	if(!front)
		return;
	else if(front->next)
		front = front->next;

	/* 
	 * Traverse through list and compare the back and front number.
	 * if numbers are duplicate, change the back link to next element of
	 * front node and free front node.
	 */	
	while(front) {
		if(front->number == back->number) {
			back->next = front->next;
			free(front);
			/* 
			 * front pointer is freed, hence, set the front to next
			 * element
			 */
			front = back->next;		
		} else {
			front = front->next;
			back = back->next;
		}
	}
}

// main function.
int main()
{
        int i = 0, x = 100;
        struct node *head = NULL; /* Create head point to point to head of the linked list. */
	
	insertStart(&head, 5);
	insertStart(&head, 5);
	insertStart(&head, 4);
	insertStart(&head, 3);
	insertStart(&head, 3);
	insertStart(&head, 2);
	insertStart(&head, 2);
	insertStart(&head, 1);

	removeDuplicateElements(&head);
        traverseNode(head);
        printf("\n");	
}
