#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;

void enqueue(Node **head, Node **tail, int data, int pri) {
	
	Node *temp = *head;

	Node *newNode = (Node *)malloc(sizeof(Node));
	if(!newNode) {
		return;	
	} else {
		memset(newNode, 0, sizeof(Node));
		newNode->data = data;
		newNode->priority = pri;
	}

	if(*head == NULL) {
		*head = newNode;
		*tail = newNode;
	} else {
		newNode->next = *head;
		*head = newNode;
	}
}

void peek(Node *ptr) {

	if(!ptr) {
		printf("Queue is EMPTY\n");
		return;
	}
	while(ptr) {
		printf("|%d|%d| --> ", ptr->data, ptr->priority);
		ptr = ptr->next;
	}
	printf("NULL\n\n");
}

void dequeue(Node **head) {
	Node *temp = *head;
	int pri = 0;
	Node *freeNode = NULL;
	Node *freeBack = NULL;
	Node *b = *head;
	Node *f = *head;

	if(*head == NULL) {
		printf("Queue is EMPTY\n");
		return;
	}
	 fN Fb
	  b f         
// 	|60|6| --> |50|2| --> |40|3| --> |30|4| --> |20|5| --> NULL

	while(f) {
		if(pri <= f->priority) {
			pri = f->priority;
			freeNode = f;
			freeBack = b;
		}
		if(f != b)
			b = b->next;
		f = f->next;
	}	

	/* To take care of the priority queue when only one node is pending. */
	if(freeBack == *head) {
		*head = freeNode->next;
		printf("freeing_1 %d pri %d\n", freeNode->data, freeNode->priority);
		free(freeNode);
		freeNode = NULL;
		return;
	}

	freeBack->next = freeNode->next;
	printf("freeing_2 %d pri %d\n", freeNode->data, freeNode->priority);
	free(freeNode);
	freeNode = NULL;
	freeBack = NULL;
//	peek(*head);
}

void main ()
{
	int i = 0, x, num, loopBreaker = 1, priority;
	Node *head = NULL, *tail = NULL;

	enqueue(&head, &tail, 10, 6);
	enqueue(&head, &tail, 20, 5);
	enqueue(&head, &tail, 30, 4);
	enqueue(&head, &tail, 40, 3);
	enqueue(&head, &tail, 50, 2);
	enqueue(&head, &tail, 60, 6);
	peek(head);
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	dequeue(&head);
	return;

	/* Create head point to point to head of the linked list. */
	while(loopBreaker) {
		printf("Enter your choice:\n   1. Insert an element in Circular linked list\n   2. Delete an element in Circular linked list\n   3. Print Circular linked list\n   4. Exit\n");
		scanf("%d", &x);

		switch(x) {
			case 1:
				printf("Enter a num: ");
				scanf("%d", &num);
				printf("Enter priority: ");
				scanf("%d", &priority);
				enqueue(&head, &tail, num, priority);
				printf("\nElexment %d added.\n", num);
				break;

			case 2:
				dequeue(&head);
				break;

			case 3:
				peek(head);
				break;
			case 4:
			default:
				loopBreaker = 0;
				printf("**** Invalid input ****\n");
				break;
		}
	}

	/* Test data set   
	   enqueue(&head, &tail, 10, 6);
	   enqueue(&head, &tail, 20, 5);
	   enqueue(&head, &tail, 30, 4);
	   enqueue(&head, &tail, 40, 3);
	   enqueue(&head, &tail, 50, 2);
	   enqueue(&head, &tail, 60, 1);
	   peek(head);
	   dequeue(&head);
	   dequeue(&head);
	   dequeue(&head);
	   dequeue(&head);
	   dequeue(&head);
	   dequeue(&head);
	   */
}
