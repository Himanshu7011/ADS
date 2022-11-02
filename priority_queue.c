#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    int priority;
    struct node *next;
} Node;
void enqueue();
void dequeue();
void peek();

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

	while(ptr) {
		printf("data = %d, priority = %d\n", ptr->data, ptr->priority);
		ptr = ptr->next;
	}
	printf("\n");
}

void dequeue(Node **head, Node **tail) {
	Node *temp = *head;
	Node *freeNode = NULL;
	Node *backNode = NULL;
	int pri = 0;

	if(*head == NULL)
		return;
	else {
		backNode = temp;
		temp = temp->next;
	}

	if(*head == *tail) {
		free(*head);
		*head = NULL;
		*tail = NULL;
		return;
	}
/*
	data = 60, priority = 3
	data = 50, priority = 3
	data = 40, priority = 1
	data = 30, priority = 2
	data = 20, priority = 4
	data = 10, priority = 1
*/
	pri = temp->priority;
	freeNode = temp;
	printf("\n ============================================= \n");
	while(backNode) {
		if(pri > backNode->priority) {
			pri = backNode->priority;
			freeNode = temp;
			printf("freeNode = %d, priority = %d\n", freeNode->data, freeNode->priority);
		}
		backNode = backNode->next;
		temp = temp->next;
	}
	printf("\n ============================================= \n");
}

void main ()
{
	Node *head = NULL, *tail = NULL;
	enqueue(&head, &tail, 10, 1);
	enqueue(&head, &tail, 20, 4);
	enqueue(&head, &tail, 30, 2);
	enqueue(&head, &tail, 40, 1);
	enqueue(&head, &tail, 50, 3);
	enqueue(&head, &tail, 60, 3);
//	peek(head);
	dequeue(&head, &tail);
	peek(head);
}
