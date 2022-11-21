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

struct node *mergeSortedList(struct node **hptr1, struct node **hptr2) {

	/* Write code to merge the sorted linked list */
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
        struct node *head_1 = NULL, *tail_1 = NULL; 
        struct node *head_2 = NULL, *tail_2 = NULL; 
	struct node *sortedHead = NULL;

	insertStart(&head_1, &tail_1, 1);
	insertStart(&head_1, &tail_1, 5);
	insertStart(&head_1, &tail_1, 3);
	insertStart(&head_1, &tail_1, 6);
	insertStart(&head_1, &tail_1, 2);
	insertStart(&head_2, &tail_2, 7);
	insertStart(&head_2, &tail_2, 10);
	insertStart(&head_2, &tail_2, 9);
	insertStart(&head_2, &tail_2, 4);
	insertStart(&head_2, &tail_2, 8);

        printf("\n First List \n");
        traverseNode(head_1);
        printf("\n Second List: \n");
        traverseNode(head_2);
        printf("\n");
	sortedHead = mergeSortedList(&head_1, &head_2);
	//	sortList(&head);
}
