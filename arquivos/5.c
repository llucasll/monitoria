// Questão 5, Lista 5 - Simone (Arquivo)
#include <stdio.h>

void criaArquivo(void){
	FILE *f = fopen("bin.data","w");
	
	int x[4], i;
	for(i=0; i<4; i++){
		printf("Digite um numero: ");
		scanf("%d", &x[i]);
	}
	
	fwrite(x, sizeof(int), 4, f);
	
	fclose(f);
}

void corrige(void){
	int x;
	FILE *f = fopen("bin.data","r+");
	
	printf("Digite uma posicao: ");
	scanf("%d", &x);
	
	fseek(f, (x-1)*sizeof(int), SEEK_SET);
	fread(&x, sizeof(int), 1, f);
	
	x++;
	
	fseek(f, -1*sizeof(int), SEEK_CUR);
	fwrite(&x, sizeof(int), 1, f);
	
	fclose(f);
}

void exibe(void);

int main(void){
	criaArquivo();
	corrige();
	exibe();
}

void exibe(void){
	FILE *f = fopen("bin.data","r");
	
	int x, i;
	for(i=0; i<4; i++){
		fread(&x, sizeof(int), 1, f);
		printf("Numero %d: %d\n", i+1, x);
	}
	
	fclose(f);
}
