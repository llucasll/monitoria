/*
	Pilha implementada em Lista Simplesmente Encadeada
*/

#include <stdio.h>
#include <stdlib.h>
//#include <errno.h>

#include "../data.h"

typedef struct node{
	Elemento e;
	struct node* prox;
} Node;

Node* inicio;

// Cria um conjunto vazio
void new(void){
	close();
	inicio = NULL;
}

// Carrega os dados de data.bin, se houver; senão, cria um conjunto vazio
void init(void){
	FILE *arq = fopen("data.bin", "r");
	inicio = NULL;
	
	if(arq!=NULL){
		Elemento e;
		fread(&e, sizeof(Elemento), 1, arq);
		if(!feof(arq)){
			inicio = malloc(sizeof(Elemento));
			inicio->e = e;
			inicio->prox = NULL;
			
			Node* tmp = inicio;
			while(true){
				fread(&e, sizeof(Elemento), 1, arq);
				if(feof(arq))
					break;
				else{
					tmp->prox = malloc(sizeof(Elemento));
					tmp = tmp->prox;
					
					tmp->e = e;
					tmp->prox = NULL;
				}
			}
		}
	
		fclose(arq);
	}
}

// Sobrescreve o arquivo data.bin com o conteúdo da lista; retorna se a operacao teve erros.
bool save(void){
	FILE *arq = fopen("data.bin", "w");
	
	if(arq == NULL) return true;
	
	else{
		Node* tmp = inicio;
		while(tmp!=NULL){
			if(fwrite(&tmp->e, sizeof(Elemento), 1, arq) != 1){
				perror ("The following error occurred");
				return true; // Erro no fwrite
			}
			tmp = tmp->prox;
		}
		
		fclose(arq);
		return false;
	}
}

// Libera a memória do conjunto, para encerrar o programa
void close(void){
	Node* tmp = inicio;
	
	while(tmp!=NULL){
		inicio = inicio->prox;
		
		tmp->prox = NULL;
		free(tmp);
		
		tmp = inicio;
	}
}


// Adiciona um elemento
void add(Elemento e){
	Node* tmp = malloc(sizeof(Elemento));
	tmp->e = e;
	tmp->prox = inicio;
	inicio = tmp;
}
// Remove e retorna um Elemento
Elemento rm(void){
	Elemento e = inicio->e;	
	
	Node* tmp = inicio;
	inicio = inicio->prox;
	
	tmp->prox = NULL;
	free(tmp);
	return e;
}


// Conta os elementos
int count(void){
	Node* tmp = inicio;
	int tam=0;
	
	while(tmp!=NULL){
		tmp = tmp->prox;
		tam++;
	}
	
	return tam;
}

int max(void){
	return 0;
}

// Exibe todos os elementos, sem alterar a estrutura
void view(void){
	printf("Total de itens: %hd\n\n",count()); // Half-Decimal
	
	Node* tmp = inicio;
	while(tmp!=NULL){
		escrever(tmp->e);
		printf("\n");
		tmp = tmp->prox;
	}
}
