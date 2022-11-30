#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"headerLinkedList.h"

int swap(int *x, int *y) {
	*x ^= *y ^= *x ^= *y;
}

void sortedList(SENTINAL **hptr)
{
	/* Write code to merge the sorted linked list */
	SENTINAL *outerLoop = *hptr;
	SENTINAL *innerLoop = *hptr;
	SENTINAL *tail = NULL;
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

void layersFilteration(layerOne **ptr, layerTwo **tptr,
		layerThree **thptr, SENTINAL *mainHead)
{
	int rand = 0;
	SENTINAL *maintmp = mainHead;


	layerOne *tailOne = NULL;
	layerTwo *tailTwo = NULL;
	layerThree *tailThree = NULL;

	layerOne  *newNodeOne = NULL;
	layerTwo  *newNodeTwo = NULL;
	layerThree *newNodeThree = NULL;

	while(maintmp) {

		if(flipCoin()) {
			newNodeOne = (layerOne *)malloc(sizeof(layerOne));
			memset(newNodeOne, 0, sizeof(layerOne));

			newNodeOne->lZero = maintmp;
			if(*ptr == NULL) {
				*ptr = newNodeOne;
				tailOne = newNodeOne;
			} else {
				tailOne->next = newNodeOne;
				tailOne = tailOne->next;
			}
		}
		maintmp = maintmp->next;
	}

	layerOne *tempOne = *ptr;
	while(tempOne) {

		if(flipCoin()) {
			newNodeTwo = (layerTwo *)malloc(sizeof(layerTwo));
			memset(newNodeTwo, 0, sizeof(layerTwo));

			newNodeTwo->lOne = tempOne;

			if(*tptr == NULL) {
				*tptr = newNodeTwo;
				tailTwo = newNodeTwo;
			} else {
				tailTwo->next = newNodeTwo;
				tailTwo = tailTwo->next;
			}
		}
		tempOne = tempOne->next;
	}

	layerTwo *tempTwo = *tptr;
	while(tempTwo) {

		if(flipCoin()) {
			newNodeThree = (layerThree *) malloc(sizeof(layerThree));
			memset(newNodeThree, 0, sizeof(layerThree));

			newNodeThree->lTwo = tempTwo;

			if(*thptr == NULL) {
				*thptr = newNodeThree;
				tailThree = newNodeThree;
			} else {
				tailThree->next = newNodeThree;
				tailThree = tailThree->next;
			}
		}
		tempTwo = tempTwo->next;
	}
}

void search()
{
}

int main() {
	
	SENTINAL   *head = NULL;
	layerOne   *headOne = NULL;
	layerTwo   *headTwo = NULL;
	layerThree *headThree = NULL;


	/* Reading linkedList.txt file and create a linkedlist. */
	read_ints("linkedList.txt", &head);
	sortedList(&head);
	layersFilteration(&headOne, &headTwo, &headThree, head);
	traverseFinal(head, headOne, headTwo, headThree);

/*	traverseOne(headOne);
	traverseTwo(headTwo);
	traverseThree(headThree);
*/
}
