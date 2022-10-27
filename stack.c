/*
 * Operations to be performed by stack:
 * PUSH, POP and PEEK
 * PUSH: To push an element in stack.
 * POP: To pop back the elements from STACK.
 * PEEK: To print how many elements are there in STACK.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 10

struct node {
        int data;
        struct node *next;
};

void push(struct node **ptr, int num)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));

	/* Fill data and newNode next fields */
	newNode->data = num;
	newNode->next = *ptr;
	
	/* point top to newNode */
	*ptr = newNode;
}

void pop(struct node **ptr)
{
	if(*ptr == NULL) {
		printf("STACK IS EMPTY\n");
		return;
	}

	struct node *freeNode = *ptr;

	*ptr = (*ptr)->next;
	free(freeNode);
}

void peek(struct node *ptr)
{
	printf("Data in stack: ");
	while(ptr) {
		printf(" %d", (ptr)->data);
		ptr = ptr->next;
	}

}

int main()
{
        int i = 0, x = STACK_SIZE;
        struct node *top = NULL; /* Create top pointer to point at the head of the linked list. */
        printf("Adding node: ");
        while(i++ < STACK_SIZE) {
                push(&top, x);
                printf(" %d", x);
                x = x + 10;
        }
	if(i >= STACK_SIZE)
		printf("\nSTACK is FULL, Can't add more data in STACK\n");

        peek(top);
        printf("\nDeleting node:");
        i = 0;
        while(i++ < STACK_SIZE) {
                printf(" %d", top->data);
                pop(&top);
        }
        printf("\n");
}
