#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headerLinkedList.h"

int swap(int *x, int *y) {
	*x ^= *y ^= *x ^= *y;
}

void sortedList(mainList **hptr)
{
	/* Write code to merge the sorted linked list */
	mainList *outerLoop = *hptr;
	mainList *innerLoop = *hptr;
	mainList *tail = NULL;
	int x = 0;

	while(outerLoop) {
		while(innerLoop) {
			if(innerLoop->data < outerLoop->data)
				swap(&(innerLoop->data), &(outerLoop->data));
			innerLoop = innerLoop->next;
		}
		outerLoop = outerLoop->next;
		innerLoop = outerLoop;
	}
}

void l1Building(mainList **hptr, L1 **l1ptr, COIN *cptr)
{
	L1 *l1temp = *l1ptr;
	L1 *l1Tail = NULL;
	L1 *newL1Node = NULL;

	mainList *temp = *hptr;

	COIN *ctmp = cptr;

	while(ctmp) {
		l1temp = *l1ptr;
		if(ctmp->ht) {
			newL1Node = (L1 *)malloc(sizeof(L1));
			memset(newL1Node, 0, sizeof(L1));
			newL1Node->addr = temp;	

			if(*l1ptr == NULL) {
				*l1ptr = newL1Node;
				l1Tail = newL1Node;
			} else {
				l1Tail->next = newL1Node;
				l1Tail = l1Tail->next;
			}
		}
		temp = temp->next;
		ctmp = ctmp->next;
	}
}

int main() {
	mainList *headL0 = NULL;
	L1 *headL1 = NULL;
	L2 *headL2 = NULL;
	L3 *headL3 = NULL;
	COIN *headCoin = NULL;

	read_ints("linkedList.txt", &headL0, &headCoin);
	sortedList(&headL0);

	l1Building(&headL0, &headL1, headCoin);
	printf("\n");
	traverse(headL0, headCoin);
	printf("\n\n\n\n");
	traverseL1(headL1, headCoin);
	printf("\n");

}
