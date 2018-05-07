/*
	Pilha implementada em Array
*/

#include <stdio.h>
//#include <errno.h>

#include "../data.h"

#define MAX 2
Elemento pilha[MAX];
short tam;


// Cria um conjunto vazio
void new(void){
	tam = 0;
}

// Carrega os dados de data.bin, se houver; senão, cria um conjunto vazio
void init(void){
	FILE *arq = fopen("data.bin", "r");
	
	tam = 0;
	if(arq != (FILE *)NULL){
		while(true){
			fread(pilha+tam, sizeof(Elemento), 1, arq);
			if(feof(arq))
				break;
			else
				tam++;
			
			// A pilha não pode ter mais do que TAM elementos!
			if(tam==MAX){
				Elemento e;
				fread(&e, sizeof(Elemento), 1, arq);
				if(!feof(arq)){
					printf("\nO arquivo contem mais do que %d Elementos!\n", MAX);
					printf("Considerando apenas os %d primeiros...\n", MAX);
					break;
				}
			}
		}
	
		fclose(arq);
	}
}

// Sobrescreve o arquivo data.bin com o conteúdo da lista; retorna se a operacao teve erros.
bool save(void){
	FILE *arq = fopen("data.bin", "w");
	
	if(arq == (FILE *)NULL) return true;
	
	else{
		int i;
		for(i=0; i<tam; i++){
			if(fwrite(pilha+i, sizeof(Elemento), 1, arq) != 1){
				perror ("The following error occurred");
				return true; // Erro no fwrite
			}
		}
	
		fclose(arq);
		return false;
	}
}

// Libera a memória do conjunto, para encerrar o programa
void close(void){}


// Adiciona um elemento
void add(Elemento e){
	if(tam<MAX){
		pilha[tam] = e;
		tam++;
	}
	else
		printf("\nErro!! Tentativa de inserir um Elemento no Conjunto cheio!\n");
}
// Remove e retorna um Elemento
Elemento rm(void){
	if(tam>0)
		tam--;
	return pilha[tam]; // vai ficar a cargo do programa principal detectar o erro.
}


// Conta os elementos
int count(void){
	return tam;
}

int max(void){
	return MAX;
}

// Exibe todos os elementos, sem alterar a estrutura
void view(void){
	printf("Total de itens: %hd\n\n",count()); // Half-Decimal
	
	int i;
	for(i=0; i<tam; i++){
		escrever(pilha[i]);
		printf("\n");
	}
}
