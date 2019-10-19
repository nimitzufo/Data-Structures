#include <stdio.h>
#include <stdlib.h>

typedef struct node* Stack;
typedef struct node Node;

struct node{
	int num; //content
	struct node *next;	
};

Stack *st;

//create stack
Stack* createStack(){
	Stack* st = (Stack*) malloc(sizeof(Stack));
	if(st != NULL)
		st* = NULL;
	return st;
}

//delete stack
void freeStack(Stack *st){
	if(st != NULL){
		Node* node;
		while((*st)!=NULL){
			node = *st;
			*st = (*st)->next;
			free(node);
		}
		free(st);
	}
}

//size of stack
int stackSize(Stack *st){
	if(st==NULL) return 0;
	int count = 0;
	Node* node = *st;
	while(node != NULL){
		count++;
		node = node->next;
	}
	return count;
}

//check empty stack
int emptyStack(Stack * st){
	if(st == NULL) return 1;
	if(*st == NULL) return 1;
	return 0;
}


//add element to stack
int addStack(Stack *st, int n){
	if(st == NULL) return 0;
	Node* node = (Node*) malloc(sizeof(Node));
	if(node == NULL) return 0;
	node->num = n;
	node->next = (*st);
	*st = node;
	return 1;
}

//delete element
int eraseStackNode(Stack *st){
	if(st == NULL) return 0;
	if(*st == NULL) return 0;
	Node *node = (*st);
	*st = node->next;
	free(node);
	return 1;
}

//check element
int checkStack(Stack* st, int *n){
	if(st == NULL) return 0;
	if((*st)==NULL) return 0;
	*n = (*st)->num;
	return 1;
}

