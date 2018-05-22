#include <stdio.h>

#define TAM 6

int maior(int vet[], int x, int y){
	if(x == y)
		return vet[x];
	else{
		int tmp = maior(vet, x+1, y);
		if(vet[x] > tmp)
			return vet[x];
		else
			return tmp;
	}
}

int main(void){
	int vet[TAM];
	int i;
	
	for(i=0; i<TAM; i++){
		printf("Digite um numero: ");
		scanf("%d",&vet[i]);
	}
	
	printf("\nO maior numero foi: %d\n", maior(vet, 0, TAM-1) );
}
