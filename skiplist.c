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

void l2Binding(L1 *l1ptr, L2 **l2ptr)
{
	L2 *l2temp = *l2ptr;
	L2 *l2Tail = NULL;
	L2 *newL2Node = NULL;
	int rand = 0;

	L1 *temp = l1ptr;

	while(temp) {
		
		l2temp = *l2ptr;
		if(rand = flip()) {
			newL2Node = (L2 *)malloc(sizeof(L2));
			memset(newL2Node, 0, sizeof(L2));
			newL2Node->addr = temp->addr;	
			newL2Node->rand = rand;
			if(*l2ptr == NULL) {
				*l2ptr = newL2Node;
				l2Tail = newL2Node;
			} else {
				l2Tail->next = newL2Node;
				l2Tail = l2Tail->next;
			}
		} 
		temp = temp->next;
	}
}


void l3Binding(L2 *l2ptr, L3 **l3ptr)
{
	L3 *l3temp = *l3ptr;
	L3 *l3Tail = NULL;
	L3 *newL3Node = NULL;
	int rand = 0;

	L2 *temp = l2ptr;

	while(temp) {
		
		l3temp = *l3ptr;
		if(rand = flip()) {
			newL3Node = (L3 *)malloc(sizeof(L3));
			memset(newL3Node, 0, sizeof(L3));
			newL3Node->addr = temp->addr;	
			newL3Node->rand = rand;
			if(*l3ptr == NULL) {
				*l3ptr = newL3Node;
				l3Tail = newL3Node;
			} else {
				l3Tail->next = newL3Node;
				l3Tail = l3Tail->next;
			}
		} 
		temp = temp->next;
	}
}

int main() {
	mainList *headL0 = NULL;
	L1 *headL1 = NULL;
	L2 *headL2 = NULL;
	L3 *headL3 = NULL;
	int find = 0;

	read_ints("linkedList.txt", &headL0);
	sortedList(&headL0);

	l1Building(headL0, &headL1);
	printf("\n Main Linked List: \n");
	traverse(headL0);
	l2Binding(headL1, &headL2);
	l3Binding(headL2, &headL3);
	printf("\n L1 List: \n");
	traverseL1(headL1);
	printf("\n L2 List: \n");
	traverseL2(headL2);
	printf("\n L3 List: \n");
	traverseL3(headL3);
	printf("\n");
	printf("Enter a number to find: ");
	scanf("%d", &find);
	search(headL3, headL2, headL1, find);
}
