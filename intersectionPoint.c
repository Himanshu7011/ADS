#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

/* Insert a new element in the list */
void insertStart(struct node **ptr, struct node **tail, int num)
{
	/* Create a memory for new node */
	struct node *newNode = (struct node *) malloc(sizeof(struct node));
	memset(newNode, 0, sizeof(struct node));

	/* Fill in the data in newly created node */
	if(*tail == NULL)
		*tail = newNode;
	newNode->data = num;
	newNode->next = *ptr;

	*ptr = newNode;
}

/* Print the elements of linked list */
void traverseNode(struct node *ptr)
{
	printf("\n");
	while(ptr) {
		printf("| %d | --> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void intersectionPoint(Node *hptr1, Node *hptr2) {

	Node *temp = hptr2;

	while(hptr1){
		while(hptr2) {
			if(hptr1 == hptr2) {
				printf("PointOfInersection: %p :: %d\n",
					hptr1, hptr1->data);
				return;
			}
			hptr2 = hptr2->next;
		}
		hptr2 = temp;
		hptr1 = hptr1->next;
	}
}

int main(){

	Node *headFirst = NULL, *headSec = NULL, *headTh = NULL;
	Node *tailFirst = NULL, *tailSec = NULL, *tailTh = NULL;
	int i = 0, random = 0;
	int num = 0;

	num = rand() % 10;
	for(i=0; i<num; i++) {
		random = rand() % 10;
		insertStart(&headFirst, &tailFirst, random);
	}

	num = rand() % 10;
	for(i=0; i<5; i++) {
		random = rand() % 10;
		insertStart(&headSec, &tailSec, random);
	}

	num = rand() % 10;
	for(i=0; i<5; i++) {
		random = rand() % 10;
		insertStart(&headTh, &tailTh, random);
	}

	printf("\nIntersion Point = %p :: %d\n", headTh, headTh->data);
	traverseNode(headTh);

	tailFirst->next = headTh;
	tailSec->next = headTh;

	printf("\nFirst List:\n");
	traverseNode(headFirst);

	printf("\nSecond List:\n");
	traverseNode(headSec);

	intersectionPoint(headFirst, headSec);

}
