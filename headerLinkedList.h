#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct sentinal {
	int data;
	struct sentinal *next;
} SENTINAL;

typedef struct layerOne {
	SENTINAL *lZero;
	struct layerOne *next;
} layerOne;

typedef struct layerTwo {
	layerOne *lOne;
	struct layerTwo *next;
} layerTwo;

typedef struct layerThree {
	layerTwo *lTwo;
	struct layerThree *next;
} layerThree;

int flipCoin()
{
	int x = rand() % 2;
	if(x == 0)
		return 0;
	else
		return 1;
}

void read_ints (const char* file_name, SENTINAL **hptr)
{
	FILE* file = fopen (file_name, "r");
	SENTINAL *temp = *hptr, *newNode = NULL;
	int i = 0;

	while (fscanf (file, "%d", &i) == 1)
	{  
		temp = *hptr;
		newNode = (SENTINAL *)malloc(sizeof(SENTINAL));
		memset(newNode, 0, sizeof(SENTINAL));

		newNode->data = i;

		if(*hptr == NULL) {
			*hptr = newNode;
		} else {
			*hptr = newNode;
			newNode->next = temp;
		}
	}
	fclose (file);        
}

void traverse(SENTINAL *ptr)
{
	printf(" ======= Main List ======= \n");
	while(ptr) {
		printf("	| %d | <===== | %p |\n", ptr->data, ptr);
		ptr = ptr->next;
	}
	printf("NULL\n\n");
}


void traverseFinal(SENTINAL *ptr, layerOne *optr,
		layerTwo *tptr, layerThree *thptr)
{

	printf(" ======= Main List ======= \n");
	while(ptr) {
		printf("| %p | <== | %p |\n", ptr->data, ptr);
		ptr = ptr->next;
	}

	printf("\n\n ======= L0 ======= \n");
	while(optr) {
		printf(" <== | %p | <== | %p |\n", optr->lZero, optr);
		optr = optr->next;
	}

	printf("\n\n ======= L1 ======= \n");
	while(tptr) {
		printf(" <== | %p | <== | %p |\n", tptr->lOne, tptr);
		tptr = tptr->next;
	}

	printf("\n\n ======= L2 ======= \n");
	while(thptr) {
		printf(" <== | %p | <== | %p |\n", thptr->lTwo, thptr);
		thptr = thptr->next;
	}

	printf("NULL\n\n");
}


/*void traverseFinal(SENTINAL *ptr, layerOne *optr,
		layerTwo *tptr, layerThree *thptr)
{

	printf(" ======= Main List ======= \n");
	while(ptr) {
		printf("| %p | <== | %p |\n", ptr->data, ptr);
		ptr = ptr->next;
	}

	printf("\n\n ======= L0 ======= \n");
	while(optr) {
		printf(" <== | %p | <== | %p |\n", optr->lZero, optr);
		optr = optr->next;
	}

	printf("\n\n ======= L1 ======= \n");
	while(tptr) {
		printf(" <== | %p | <== | %p |\n", tptr->lOne, tptr);
		tptr = tptr->next;
	}

	printf("\n\n ======= L2 ======= \n");
	while(thptr) {
		printf(" <== | %p | <== | %p |\n", thptr->lTwo, thptr);
		thptr = thptr->next;
	}

	printf("NULL\n\n");
}
*/
