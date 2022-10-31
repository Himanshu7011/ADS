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

void traverseNode(struct node *);
void deleteNode(struct node **ptr, struct node **rear)
{

	struct node *freeNode = *ptr;

	if(*ptr == NULL)
		return;
	if((*ptr)->next == *ptr) { /* To handle the case, when only last node is there in linked list to delete. */
		printf("\nElexment %d deleted.\n", (*ptr)->data);
		free(*ptr);
		*ptr = NULL;    /* Set the pointer to NULL once freed, else this will lead to dangling pointer */
		goto traverse;
	}
	*ptr = (*ptr)->next;
	(*rear)->next = *ptr;
	printf("\nElexment %d deleted.\n", freeNode->data);
	free(freeNode);
	freeNode = NULL;
traverse:
	traverseNode(*ptr);
}

/* Print the elements of linked list */
void traverseNode(struct node *head)
{
	/* Fix the traverse code */
	struct node *temp = head;
	
	if((head == NULL))
		return;

	do {
		printf(" %d", head->data);
		head = head->next;
	} while(head != temp);

	printf("\n");
}

// main function.
int main()
{
        int i = 0, x, num, loopBreaker = 1;
        struct node *head = NULL, *rear = NULL; /* Create head point to point to head of the linked list. */

	while(loopBreaker) {
		printf("Enter your choice:\n   1. Insert an element in Circular linked list\n   2. Delete an element in Circular linked list\n   3. Print Circular linked list\n   4. Exit\n");
		scanf("%d", &x);

		switch(x) {
			case 1:
				printf("Enter a num: ");
				scanf("%d", &num);
				insertStart(&head, &rear, num);
				printf("\nElexment %d added.\n", num);
				break;

			case 2:
				deleteNode(&head, &rear);
				break;

			case 3:
				traverseNode(head);
				break;
			case 4:
			default:
				loopBreaker = 0;
				printf("**** Invalid input ****\n");
				break;	
		}
	}
}
