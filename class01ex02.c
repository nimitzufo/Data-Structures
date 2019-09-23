#include <stdio.h>
#include <stdlib.h>

int cmpfunc(int *a, int *b){
	return *a - *b;
}

int main(){
	int v[2],i;
	for(i=0;i!=3;i++){
		scanf("%d", &v[i]);
	}
	qsort(v,3,sizeof(int),cmpfunc);
	for(i=1;i!=3;i++){
		printf("%d ", v[i]);
	}
	
	return 0;
}
