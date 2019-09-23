#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char aux[256];
	char *word=NULL;
	
	scanf("%s", aux);
	word = (char*) malloc(sizeof(char)*strlen(aux));
	strcpy(word,aux);
	printf("%c %c %d", word[0],word[strlen(word)-1], strlen(word));
	
	free(word);
	return 0;
}
