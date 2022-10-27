#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINKED_LIST_SIZE 10

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

void deleteNode(struct node **ptr)
{
	struct node *freeNode = *ptr;
	*ptr = (*ptr)->next;
	free(freeNode);
}

/* Print the elements of linked list */
void traverseNode(struct node *ptr)
{
	printf("Linked List: ");
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
                insertStart(&head, x);
		printf(" %d", x);
                x = x - LINKED_LIST_SIZE;
        }
        printf("\n");

        traverseNode(head);
        printf("\nDeleting node:");
        i = 0;
        while(i++ < LINKED_LIST_SIZE) {
		printf(" %d", head->number);
                deleteNode(&head);
        }
        printf("\n");
}
