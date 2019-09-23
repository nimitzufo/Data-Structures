#include <stdio.h>

int main(){
	int a,b,s=0;
	scanf("%d %d", &a, &b);
	if(a>b){
		s+=(a+b);
		while(a--){
			s+=a;
			if(a==b){
				break;
			}	
		}
	} else {
		s+=(a+b);
		while(b--){
			s+=b;
			if(b==a){
				break;
			}
		}
	}
	printf("%d", s);	
	return 0;
}
