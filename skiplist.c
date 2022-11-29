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

void l1Building(mainList *hptr, L1 **l1ptr)
{
	L1 *l1temp = *l1ptr;
	L1 *l1Tail = NULL;
	L1 *newL1Node = NULL;
	int rand = 0;
	mainList *temp = hptr;

	while(temp) {
		l1temp = *l1ptr;
		if(rand = flip()) {
			newL1Node = (L1 *)malloc(sizeof(L1));
			memset(newL1Node, 0, sizeof(L1));
			newL1Node->addr = temp;	
			newL1Node->rand = rand;
			if(*l1ptr == NULL) {
				*l1ptr = newL1Node;
				l1Tail = newL1Node;
			} else {
				l1Tail->next = newL1Node;
				l1Tail = l1Tail->next;
			}
		}
		temp = temp->next;
	}
}

void search(L1 *lptr, int find) 
{
	L1 *temp = lptr;
	mainList *front = NULL;
	mainList *back = NULL;

	while(temp) {
		if(temp->addr->data == find) {
			printf(" ***** FOUND [%d]\n", find);
			return;
		} else if(temp->next &&
				(temp->addr->data < find) &&
				(temp->next->addr->data > find)) { /* data < find */
			back = temp->addr;
			front = temp->next->addr;
			while(back != front) {
				if(back->data == find) {
					printf(" ***** FOUND [%d]\n", find);
					return;	
				} else
					back = back->next;
			}
		} else if(temp->next == NULL) {
			front = temp->addr;
		        while(front) {
				if(front->data == find) {
					printf(" ***** FOUND [%d]\n", find);
					return;
				}
				front = front->next;
			}
		}
		temp = temp->next;
	}
	printf(" ***** NOT FOUND [%d]\n", find);
}

int main() {
	mainList *headL0 = NULL;
	L1 *headL1 = NULL;

	read_ints("linkedList.txt", &headL0);
	sortedList(&headL0);

	l1Building(headL0, &headL1);
	traverse(headL0, headL1);
	search(headL1, 200);
	search(headL1, 1);
	search(headL1, 11);
	search(headL1, 19);
	search(headL1, 2);
	search(headL1, 7);
	search(headL1, 8);
	search(headL1, 15);
	search(headL1, 16);
	search(headL1, 17);
	search(headL1, 18);
	search(headL1, 20);
	search(headL1, 40);
	search(headL1, 31);
	search(headL1, 37);
	search(headL1, 50);
	search(headL1, 25);
	search(headL1, 29);
	search(headL1, 49);
	printf("\n\n");
}
