#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct L0 {
         int data;
         struct L0 *next;
}mainList;

typedef struct L1 {
	int rand;
	mainList *addr;
	struct L1 *next;
}L1;

typedef struct L2 {
	int rand;
	mainList *addr;
	struct L2 *next;
}L2;


typedef struct L3 {
	int rand;
	mainList *addr;
	struct L3 *next;
}L3;

int flip()
{
	int x = rand() % 2;
	if(x == 0)
		return 0;
	else
		return 1;
}

void read_ints (const char* file_name, mainList **hptr)
{
	FILE* file = fopen (file_name, "r");
	mainList *temp = *hptr, *newNode = NULL;
	int i = 0;

	fscanf (file, "%d", &i);	
	while (fscanf (file, "%d", &i) == 1)
	{  
		temp = *hptr;
		newNode = (mainList *)malloc(sizeof(mainList));
		memset(newNode, 0, sizeof(mainList));

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

void traverse(mainList *ptr)
{
	while(ptr) {
		printf("| %d |  -->  ", ptr->data);
		ptr = ptr->next;
	}
	printf(" NULL\n");
}

void traverseL1(L1 *ptr)
{
	while(ptr) {
		printf("| %d | %d | --> ", ptr->addr->data, ptr->rand);
		ptr = ptr->next;
	}
	printf(" NULL\n");
}


void traverseL2(L2 *ptr)
{
	while(ptr) {
		printf("| %d | %d | --> ", ptr->addr->data, ptr->rand);
		ptr = ptr->next;
	}
	printf(" NULL\n");
}


void traverseL3(L3 *ptr)
{
	while(ptr) {
		printf("| %d | %d | --> ", ptr->addr->data, ptr->rand);
		ptr = ptr->next;
	}
	printf(" NULL\n");
}

void search(L3 *xyz, L2 *pqr, L1 *abc, int num) {

	L3 *t3 = xyz;
	L2 *t2 = pqr;
	L1 *t1 = abc;

	while(xyz) {
		if(xyz->addr->data == num) {
			printf("\n******** [%d] Found ********\n\n", num);
			return;
		} else if(xyz->addr->data < num) {
			/* TBD */
		} else {
			/* TBD */
		}
		xyz = xyz->next;
	}
}
