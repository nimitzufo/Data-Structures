#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	node *prev;
	int number;
	node *next;
} Node;

typedef struct node* List;
//head
List *li;

//empty list check
int emptyList(List *li){
	if(li==NULL) return 1;
	else return 0;
}

//include node at beginning
List addNodeBeg(List *li, int value){
	Node *newNode;
	newNode = (Node*) malloc(sizeof(Node));
	newNode->number = value;
	newNode->prev = NULL;
	newNode->next = li;
	li->prev = newNode;
	li = newNode;
	return newNode;
}

//add at end
Node *addNodeEnd(List *li, int value){
	Node *newNode, *aux;
	newNode = (Node*) malloc(sizeof(Node));
	newNode->number = value;
	newNode->next = NULL;
	aux = li;
	while(aux->next != NULL){
		aux=aux->next;
	}
	aux->next = newNode;
	newNode->prev = aux;
	return li;
}

//add node after key element
Node *addKeyNode(List *li, int key, int value){
	Node *newNode,  *aux;
	newNode = (Node*) malloc(sizeof(Node));
	newNode->number=value;
	aux = li;
	while(aux->next->number != key){
		aux = aux->next;
	}
	newNode->next=aux->next;
	newNode->prev=aux;
	aux->next=newNode;
	newNode->next->prev=newNode;
	return li;
}

//delete elements
//beginning
Node *eraseBeg(List li){
	li = li->next;
	free(li->prev);
	li->prev = NULL;
	return li;
}

//delete tail
Node *eraseEnd(List li){
	Node *aux;
	aux = li;
	while(aux->next->next!=NULL){
		aux=aux->next;
	}
	free(aux->next);
	aux->next=NULL;
	return li;
}

//delete key element
Node *eraseKeyNode(List li, int key){
	Node *aux;
	aux=li;
	while(aux->next!=key){
		aux=aux->next;
	}
	aux->prev->next=aux->next;
	aux->next->prev=aux->prev;
	free(aux);
	return li;
}




