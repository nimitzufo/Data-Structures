#include <stdio.h>
#define TAM 10
int main(){
	int v[TAM],x,i;
	for(i=0;i!=TAM;i++){
		scanf("%d", &v[i]);
	}
	scanf("%d", &x);
	for(i=0;i!=TAM;i++){
		if(v[i]==x){
			printf("%d ", i);
		}
	}
	
	return 0;
}
