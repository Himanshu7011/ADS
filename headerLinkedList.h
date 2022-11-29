#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct L0 {
         int data;
         struct L0 *next;
}mainList;

typedef struct L1 {
	mainList *addr;
	struct L1 *next;
}L1;

typedef struct L2 {
	mainList *addr;
	struct L1 *next;
}L2;


typedef struct L3 {
	mainList *addr;
	struct L1 *next;
}L3;

typedef struct flipCoin {
	int ht;
	struct flipCoin *next;
}COIN;


int flip()
{
	int x = rand() % 2;
	if(x == 0)
		return 0;
	else
		return 1;
}

void read_ints (const char* file_name, mainList **hptr, COIN **hcoin)
{
	FILE* file = fopen (file_name, "r");
	mainList *temp = *hptr, *newNode = NULL;
	COIN *hdNode = NULL;
	COIN *coinTemp = *hcoin;
	int i = 0;

	fscanf (file, "%d", &i);	
	while (fscanf (file, "%d", &i) == 1)
	{  
		temp = *hptr;
		coinTemp = *hcoin;
		newNode = (mainList *)malloc(sizeof(mainList));
		memset(newNode, 0, sizeof(mainList));
		hdNode = (COIN *)malloc(sizeof(COIN));
		memset(hdNode, 0, sizeof(COIN));

		newNode->data = i;
		hdNode->ht = flip();

		if(*hptr == NULL) {
			*hptr = newNode;
		} else {
			*hptr = newNode;
			newNode->next = temp;
		}

		if(*hcoin == NULL) {
			*hcoin = hdNode;
		} else {
			*hcoin = hdNode;
			hdNode->next = coinTemp;
		}
	}
	fclose (file);        
}

void traverse(mainList *ptr, COIN *cptr)
{
	while(ptr) {
		printf("| %d || %d |  -->  ", ptr->data, cptr->ht);
		ptr = ptr->next;
		cptr = cptr->next;
	}
	printf(" NULL\n");
}

void traverseL1(L1 *ptr, COIN *cptr)
{
	while(ptr) {
		printf("| %d | --> ", ptr->addr->data);
		ptr = ptr->next;
	}
	printf(" NULL\n");
}
