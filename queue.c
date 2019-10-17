#include <stdio.h>
#include <stdlib.h>

struct aluno
{
	int matricula;
	char nome[30];
	float n1, n2, n3;
};

typedef struct queue Q;

Q *q;//ponteiro descritor

struct queue{
	struct no *inicio;
	struct no *final;
};

struct no{
	struct aluno data; //element
	struct no *next;
};

typedef struct no Node;

//criar fila
q = createQ();

//function createQ()
Q* createQ(){
	Q* q = (Q*) malloc(sizeof(Q));
	if(q!=NULL){
		q->final=NULL;
		q->inicio=NULL;
	}
	return q;
}

//free/erase queue
void freeQ(Q *q){
	if(q != NULL){
		Node *node;
		while(q->inicio != NULL){
			node = q->inicio;
			q->inicio = q->inicio->next;
			free(node);
		}
		free(q);
	}	
}


//check queue size

int x = qSize(q);

int qSize(Q *q){
	if(q == NULL) return 0;
	int count = 0 ;
	Node *node = q->inicio;
	while(node != NULL){
		count++;
		node = node->next;
	}
	return count;
}

//check empty q
if(emptyQ(q));

int emptyQ(Q *q){
	if(q==NULL) return 1;
	if(q->inicio == NULL) return 1;
	return 0;
}


//add element
int x = addQ(q, studentData);

int addQ(Q *q, struct aluno al){
	if(q==NULL) return 0;
	Node *node = (Node*) malloc(sizeof(Node));
	if(node==NULL) return 0;
	node->data = al;
	node->next = NULL;
	if(q->final ==NULL) //empty q
		q->inicio = node;
	else
		q->final->next = node;
	q->final = node;
	return 1;
}

//remove element 
int x = removeQ(q);

int removeQ(Q* q){
	if(q==NULL) return 0;
	if(q->inicio == NULL) return 0; //empty q
	Node *node = q->inicio;
	q->inicio = q->inicio->next;
	if(q->inicio == NULL) 
		q->final = NULL;
	free(node);
	return 1;
}


//consultar elemento
int checkQ(Q *q, struct aluno *al){
	if(q == NULL) return 0;
	if(q->inicio == NULL) return 0;
	*al = q->inicio->data;
	return 1;
}


