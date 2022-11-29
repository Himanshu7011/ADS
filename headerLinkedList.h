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

void traverse(mainList *ptr, L1 *Llist)
{
	mainList *temp = ptr;
	L1 *backList = Llist;

	printf("\n---------------------------------------------\n");
	printf("|data	    	   L0 		        L1   |\n");
	printf("---------------------------------------------\n");
	while(ptr) {
		if(Llist && ptr == Llist->addr) {
			if(ptr->data < 10) 
				printf("| %d  | ------> | %p | ------> | %p \n",
						ptr->data, ptr, Llist->addr);
			else
				printf("| %d | ------> | %p | ------> | %p \n",
						ptr->data, ptr, Llist->addr);
			Llist = Llist->next;
			ptr = ptr->next;
		} else {
			if(ptr->data < 10)
				printf("| %d  | ------> | %p | ------> | NULL \n",
						ptr->data, ptr);
			else
				printf("| %d | ------> | %p | ------> | NULL \n",
						ptr->data, ptr);
			ptr = ptr->next;
			continue;	
		}
	}
	printf("\n----------------- END ------------------\n");
	
/*	***** DEBUG CODE *****
 * 	printf("\n\n----------------- Without Null --------\n");

	ptr = temp;
	Llist = backList;

	while(ptr) {
		if(Llist && ptr == Llist->addr) {
			if(ptr->data < 10) 
				printf("| %d  | ------> | %p | ------> | %p \n",
						ptr->data, ptr, Llist->addr);
			else
				printf("| %d | ------> | %p | ------> | %p \n",
						ptr->data, ptr, Llist->addr);
			Llist = Llist->next;
			ptr = ptr->next;
		} else {
			ptr = ptr->next;
			continue;	
		}
	}
	printf("\n----------------- END ------------------\n");
*/
}

void traverseL1(L1 *ptr)
{
	while(ptr) {
		printf("| %p | --> ", ptr->addr);
		ptr = ptr->next;
	}
	printf(" NULL\n");
}
