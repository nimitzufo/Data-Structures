#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int a,b, count=0, boolAns=0;
	do{
		scanf("%d %d", &a, &b);
		while(!b){
			printf("VALOR INVÁLIDO\n");
			scanf("%d", &b);
		}
		printf("%d\n", a/b);
		count++;
		printf("VOCÊ DESEJA OUTRO CÁLCULO(S/N)?\n");
		char ans;
		fflush(stdin);
		scanf("%c", &ans);
		if(ans=='s'||ans=='S'){
			boolAns=1;
		} else {
			printf("%d", count);
			boolAns=0;
		}	
	}while(boolAns);
		
	return 0;
}
