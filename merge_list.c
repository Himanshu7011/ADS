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

/* Swap the data */
int swap(int *x, int *y) {
	*x ^= *y ^= *x ^= *y;
}


void sortedList(struct node **hptr) {

	/* Write code to merge the sorted linked list */
	struct node *outerLoop = *hptr;
	struct node *innerLoop = *hptr;
	struct node *tail = NULL;
	int x = 0;

	/*  | 1 | --> | 5 | --> | 3 | --> | 6 | --> | 2 | --> NULL  */
	while(outerLoop) {
		while(innerLoop) {
			if(innerLoop->number < outerLoop->number)
				swap(&(innerLoop->number), &(outerLoop->number));
			innerLoop = innerLoop->next;
		}
		outerLoop = outerLoop->next;
		innerLoop = outerLoop;
	}
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

struct node *mergeSortList(struct node *first, struct node *second) {

	struct node *thirdNode = NULL;
	struct node *head = NULL;
	struct node *tail = NULL;

	while(first && second) {
		/* Allocate memory for new node */
		thirdNode = (struct node *)malloc(sizeof(struct node));
		if(!head) {
			head = thirdNode;
			tail = head;
		} else {
			tail->next = thirdNode;
			tail = thirdNode;
		}
		/* Check which member is smaller.
		 * Put the smaller number in new list */
		if(first && second && (first->number < second->number)) {
			thirdNode->number = first->number;
			first = first->next;
		} else if(first && second && (second->number < first->number)) {
			thirdNode->number = second->number;
			second = second->next;
		} else {
			thirdNode->number = second->number;
			second = second->next;
			first = first->next;	
		}
	}

	/* If first list is empty, keep filling the new list with the
	 * second list pending elements. */
	while(second) {
		thirdNode = (struct node *)malloc(sizeof(struct node));
		tail->next = thirdNode;
		tail = thirdNode;
		thirdNode->number = second->number;
		second = second->next;
	}

	/* If second list is empty, keep filling the new list with the
	 * first list pending elements. */
	while(first) {
		thirdNode = (struct node *)malloc(sizeof(struct node));
		tail->next = thirdNode;
		tail = thirdNode;
		thirdNode->number = first->number;
		first = first->next;
	}
	return head;
}

/* main function */
int main() {

	/* Create head point to point to head of the linked list. */
	struct node *head_1 = NULL, *tail_1 = NULL; 
	struct node *head_2 = NULL, *tail_2 = NULL; 
	struct node *sortedHead = NULL;

	insertStart(&head_1, &tail_1, 1);
	insertStart(&head_1, &tail_1, 9);
	insertStart(&head_1, &tail_1, 3);
	insertStart(&head_1, &tail_1, 7);
	insertStart(&head_1, &tail_1, 5);

/*	insertStart(&head_1, &tail_1, 15);
	insertStart(&head_1, &tail_1, 13);
	insertStart(&head_1, &tail_1, 18);
	insertStart(&head_1, &tail_1, 12);
	insertStart(&head_1, &tail_1, 20);

	insertStart(&head_2, &tail_2, 14);
	insertStart(&head_2, &tail_2, 17);
	insertStart(&head_2, &tail_2, 16);
	insertStart(&head_2, &tail_2, 19);
	insertStart(&head_2, &tail_2, 11);
*/
	insertStart(&head_2, &tail_2, 8);
	insertStart(&head_2, &tail_2, 10);
	insertStart(&head_2, &tail_2, 4);
	insertStart(&head_2, &tail_2, 2);
	insertStart(&head_2, &tail_2, 6);

	printf("\n Sorted List I: \n");
	sortedList(&head_1);
	traverseNode(head_1);
	printf("\n");

	printf("\n Sorted List II: \n");
	sortedList(&head_2);
	traverseNode(head_2);
	printf("\n");

	sortedHead = mergeSortList(head_1, head_2);
	printf("\n Final Sorted List: \n");
	traverseNode(sortedHead);
	printf("\n");
}
