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

void rightShiftNthTimesList(struct node **hptr, int n) {
	
	struct node *front = *hptr;	
	struct node *back = *hptr;
	struct node *temp = NULL;
	int count = 0;

// 	  h		      b         f
//	| 1 | --> | 2 | --> | 3 | --> | 4 | --> | 5 | --> | 6 | --> NULL

// 	 h
// 	 f		      b         
//	| 4 | --> | 5 | --> | 6 | --> | 1 | --> | 2 | --> | 3 | --> NULL

	if(!front)
		return;
	else if(front->next)
		front = front->next;
	else
		return;

	while(front) {
		count++;
		front = front->next;
	}
	
	count = count - n;
	if(!count) {
		printf("*********** Nothing to Shift ************\n");
		return;
	}
	front = (*hptr)->next;

	while(count--) {
		front = front->next;
		back = back->next;
	} 

	back->next = NULL;
	temp = front;
	
	while(temp->next)
		temp = temp->next;

	temp->next = *hptr;
	*hptr = front;
}

// main function.
int main()
{
        int i = 0, x = 100;
        struct node *head = NULL;
        printf("Adding node: ");
	insertStart(&head, 6);
	insertStart(&head, 5);
	insertStart(&head, 4);
	insertStart(&head, 3);
	insertStart(&head, 2);
	insertStart(&head, 1);

        traverseNode(head);
        printf("********* 3SHIFT *********\n");
	rightShiftNthTimesList(&head, 3);
        traverseNode(head);
        printf("********* 2SHIFT *********\n");
	rightShiftNthTimesList(&head, 2);
        traverseNode(head);
        printf("********* 4SHIFT *********\n");
	rightShiftNthTimesList(&head, 4);
        traverseNode(head);
        printf("********* 5SHIFT *********\n");
	rightShiftNthTimesList(&head, 5);
        traverseNode(head);
        printf("********* END *********\n");
}
