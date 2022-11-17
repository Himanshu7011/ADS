#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINKED_LIST_SIZE 10

struct node {
	int number;
	struct node *next;
};

/* Insert a new element in the list */
void insertStart(struct node **ptr, struct node **tptr, int num)
{
	/* Create a memory for new node */
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	memset(newNode, 0, sizeof(struct node));

	/* Fill in the data in newly created node */
	if(*ptr == NULL) {
		newNode->number = num;
		*ptr = newNode;
		*tptr = newNode;	
	}

	newNode->number = num;
	(*tptr)->next = newNode;
	*tptr = (*tptr)->next;
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
	printf("\nLinked List: ");
	while(ptr) {
		printf("| %d |  -->  ", ptr->number);
		ptr = ptr->next;
	}
	printf("NULL\n");
}


void delNthFromEnd(struct node **hptr, struct node **tptr, int dnum) {

	struct node *front = *hptr, *back = *hptr;
	int count = 0;

	/* To Count the total nodes. */
	while(front) {
		count++;
		front = front->next;
	}

	count = count - dnum;
	
	if(!count) {

		*hptr = (*hptr)->next;
		free(back);

	} else {

		back = *hptr;
		front = back->next;
		while(--count) {
			front = front->next;
			back = back->next;
		}
		back->next = front->next;
		free(front);
	}
}

// main function.
int main()
{
        int i = 0, x = 10;
	/* Create head point to point to head of the linked list. */
        struct node *head = NULL, *tail = NULL; 
        while(i++ < LINKED_LIST_SIZE) {
                insertStart(&head, &tail,  x);
                x = x + LINKED_LIST_SIZE;
        }
        printf("\n");

        traverseNode(head);
        printf("\n");
	
	/* Test Data Set */
	delNthFromEnd(&head, &tail, 1);
        traverseNode(head);
        printf("\n");
	delNthFromEnd(&head, &tail, 2);
        traverseNode(head);
        printf("\n");
	delNthFromEnd(&head, &tail, 3);
        traverseNode(head);
        printf("\n");
	delNthFromEnd(&head, &tail, 4);
        traverseNode(head);
        printf("\n");
	delNthFromEnd(&head, &tail, 5);
        traverseNode(head);
        printf("\n");
	delNthFromEnd(&head, &tail, 5);
        traverseNode(head);
        printf("\n");
}
