#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
        int data;
        struct node *next;
        struct node *prev;
} LPFC_NODE;

void own_delMiddle(LPFC_NODE **);

LPFC_NODE *own_alloc(int d)
{
        LPFC_NODE *newNode = (LPFC_NODE *)malloc(sizeof(LPFC_NODE));
        memset(newNode, 0, sizeof(LPFC_NODE));
        newNode->data = d;
	return(newNode);
}

void own_insertEnd(LPFC_NODE **h, LPFC_NODE **t, int d) 
{
	LPFC_NODE *newEndNode = own_alloc(d);

		/* To Add First Member */
	if(*h == NULL) {
		*h = newEndNode;
		*t = newEndNode;
		return;
	} else {
		(*t)->next = newEndNode;
		newEndNode->prev = *t;
		*t = (*t)->next;
	}
}

void own_insertHead(LPFC_NODE **h, LPFC_NODE **t, int d)
{
	LPFC_NODE *temp = *h;
	LPFC_NODE *newHeadNode = own_alloc(d);

	if(*h == NULL) {
		*h = newHeadNode;
		*t = newHeadNode;
		return;
	} else {
		temp->prev = newHeadNode;
		newHeadNode->next = temp;
		*h = newHeadNode;
	}
}

void own_peek(LPFC_NODE *h) 
{
	if(!h) {
		printf("*** Empty ***\n");
		return;
	}
	while(h) {
		printf("| %d | --> ", h->data);
		h = h->next;
	}
	printf("NULL\n");
}	

void own_reverse_peek(LPFC_NODE *t) 
{
	while(t) {
		printf("| %d | --> ", t->data);
		t = t->prev;
	}
	printf("NULL\n");
}

void own_insertMiddle(LPFC_NODE **h, LPFC_NODE **t, int d) 
{
	LPFC_NODE *temp = *h;
	LPFC_NODE *tail = *t;
	LPFC_NODE *newMidNode = own_alloc(d);

	if(*h == NULL) {
		*h = newMidNode;
		*t = newMidNode;
		return;		
	} else {

//		    temp 	tail
//	| 10 | --> | 20 | --> | 30 | --> | 40 | --> NULL
		if(*h == *t)
			return;
		while(temp->next != tail) {
			temp = temp->next;	
			tail = tail->prev;
		}
			
	}
}

void own_delEnd(LPFC_NODE **h, LPFC_NODE **t) {

	LPFC_NODE *freeNode = *t;

	if(*t == NULL) {
		printf("*** List is empty *** \n");
		return;
	} else if((*t)->prev) {
		*t = (*t)->prev;
		free(freeNode);
		return;
	} else {
		free(*t);
		*t = NULL;
	}
}

void own_delHead(LPFC_NODE **h)
{
	LPFC_NODE *freeNode = *h;
	LPFC_NODE *temp = *h;
	if(temp == NULL) {
		printf("*** List is empty *** \n");
		return;
	} else {
		if((temp)->next) {
			temp = temp->next;
			*h = temp;
			temp->prev = NULL;
		} else {
			*h = NULL;
		}
		free(freeNode);
	}
}

int main() {

	LPFC_NODE *head = NULL;
	LPFC_NODE *tail = NULL;
	own_insertHead(&head, &tail, 10);
	own_insertHead(&head, &tail, 20);
	own_insertHead(&head, &tail, 30);
	own_insertHead(&head, &tail, 40);
	own_peek(head);
	own_delHead(&head);
	own_delHead(&head);
	own_delHead(&head);
	own_delHead(&head);
	own_peek(head);
}
