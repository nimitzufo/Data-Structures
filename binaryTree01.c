//Árvore binária de pesquisa
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
  TIPOCHAVE chave;
  /*dados armazenados aqui*/
  struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT inicializa(){
  return(NULL);
}
//inserção de elemento
PONT adiciona(PONT raiz, PONT no){
  if(raiz == NULL) return(no);
  if(no->chave < raiz->chave)
    raiz->esq = adiciona(raiz->esq, no);
  else
    raiz->dir = adiciona(raiz->dir, no);
  //ignorando chave igual
  return(raiz);
}
//criando novo nó
PONT criaNovoNo(TIPOCHAVE ch){
  PONT novoNO = (PONT)malloc(sizeof(NO));
  novoNO->esq = NULL;
  novoNO->dir = NULL;
  novoNO->chave = ch;
  return(novoNO);
}
//busca binária
PONT contem(TIPOCHAVE ch, PONT raiz){
  if(raiz==NULL) return(NULL);
  if(raiz->chave == ch) return(raiz);
  if(raiz->chave>ch)
    return(contem(ch,raiz->esq));
  return(contem(ch,raiz->dir));
}
//contagem de elementos
int numeroNos(PONT raiz){
  if(!raiz) return 0;
  return(numeroNos(raiz->esq))
    +1
    +numeroNos(raiz->dir);
}

int main() {
  PONT r = inicializa();
  PONT no = criaNovoNo(23);
  r = adiciona(r,no);
  PONT no2 = criaNovoNo(12);
  r = adiciona(r,no2);
  PONT no3 = criaNovoNo(25);
  r = adiciona(r,no3);
  PONT no4 = criaNovoNo(8);
  r = adiciona(r,no4);
  PONT no5 = criaNovoNo(19);
  r = adiciona(r,no5);
  PONT p = contem(12,r);
  printf("%d\n", numeroNos(r));

  return 0;
}
