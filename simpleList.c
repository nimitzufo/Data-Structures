#include <stdio.h>
#include <stdlib.h>

typedef struct node *List;

struct node{
	int num;
	node *next;
};

typedef struct node Node;

//head
List *li;

//function create list
List *createList(){
	List* li = (List*) malloc(sizeof(List));
	if(li!=NULL)
		*li=NULL;
	return li;
}

//main 
li = createList();

//function erase list
void eraseList(List* li){
	if (li!=NULL){
		Node* node;
		while((*li)!=NULL){
			node = *li;
			*li = *li->next;
			free(node);
		}
		free(li);
	}
}


//function listSize (size of list)
int listSize(List* li){
	if(li==NULL) return 0;
	int count = 0;
	Node* node = *li;
	while(node!=NULL){
		count++;
		node = node->next;
	}
	return count;
}

//check empty list (boolean)
int emptyList(List* li){
	if(li==NULL)
		return 1;
	if(*li==NULL)
		return 1;
	return 0;
}

//main
if(emptyList(li));

//add node
//at beginning
int addNodeBeg(List* li, int n){
	if(li==NULL) return 0;
	Node* node = (Node*) malloc(sizeof(Node));
	if(node==NULL) return 0;
	node->num = n;
	node->next = (*li);
	*li=node;
	return 1;
}

//add node at end 
int addNodeEnd(List* li, int n){
	if(li=NULL) return 0;
	Node *node = (Node*) malloc(sizeof(Node));
	if(node == NULL) return 0;
	node->num=n;
	node->next=NULL;
	if((*li)==NULL){
		*li = node;
	} else {
		Node *aux = *li;
		while(aux->next!=NULL){
			aux = aux->next;
		}
		aux->next = node;
	}
	return 1;
}


//add before key
int addKeyNode(List *li, int key, int n){
	Node *newNode, *aux;
	newNode = (Node*) malloc(sizeof(Node));
	newNode->num = n;
	aux = li;
	while(aux->next->n != key){
		aux = aux->next;
	}
	newNode->next = aux->next;
	aux->next = newNode;
	return 1;
}

//erase elements(nodes)
//from beginning
int eraseBeg(List *li){
	if(li == NULL)
		return 0;
	if((*li)==NULL)//empty list
		return 0;
	Node *node = *li;
	*li= node->next;
	free(node);
	return 1;
}

//erase from end
int eraseEnd(List *li){
	if(li==NULL) return 0;
	if((*li)==NULL)//empty list
		return 0;
	Node *prev, *node = *li;
	while(node->next != NULL){
		prev = node;
		node = node->next;
	}
	if(node == (*li)) //remove first
		*li = node->next;
	else
		prev->next = node->next;
	free(node);
	return 1;
}


//erase given element
int eraseNode(List *li, int n){
	if(li==NULL) return 0;
	Node *prev, *node = *li;
	while(node != NULL && node->num != n){
		prev = node;
		node = node->next;
	}
	if(node == NULL) return 0;//element not found
	if(node == *li)//remove first
		*li = node->next;
	else
		prev->next = node->next;
	free(node);
	return 1;
}


//search element(node)
//by position/by content
int searchPos(List *li, int pos, int *n){
	if(li==NULL||pos<=0) return 0;
	Node *node = *li;
	int i = 1;
	while(node != NULL && i<pos){
		node = node->next;
		i++;
	} 	
	if(node==NULL)
		return 0;
	else{
		*n = node->num;
		return 1;
	}
}

//by content
int searchCont(List *li, int numb, int *n){
	if(li==NULL) return 0;
	Node *node = *li;
	while(node != NULL && node->num != numb){
		node = node->next;
	}
	if(node==NULL)
		return 0;
	else {
		*n = node->num;
		return 1;
	}
}

