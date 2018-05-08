/*
	Filha implementada em Array
*/

#include <stdio.h>
//#include <errno.h>

#include "../data.h"

#define MAX 4
Elemento fila[MAX];
short pri, tam; // Posição do primeiro Elemento dentro do Array, e tamanho da Fila


// Cria um conjunto vazio
void new(void){
	pri = tam = 0;
}

short pos(short i){ // Retorna a posição do elemento i dentro do Array
	if(i>=0)
		return (pri+i)%MAX;
	else return MAX + i;
}

// Carrega os dados de data.bin, se houver; senão, cria um conjunto vazio
void init(void){
	FILE *arq = fopen("data.bin", "r");
	
	tam = 0;
	if(arq != (FILE *)NULL){
		while(true){
			fread(fila+tam, sizeof(Elemento), 1, arq);
			if(feof(arq))
				break;
			else
				tam++;
			
			// A fila não pode ter mais do que MAX elementos!
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
			if(fwrite(fila+pos(i), sizeof(Elemento), 1, arq) != 1){
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
		fila[pos(tam)] = e;
		tam++;
	}
	else
		printf("\nErro!! Tentativa de inserir um Elemento no Conjunto cheio!\n");
}
// Remove e retorna um Elemento
Elemento rm(void){
	if(tam>0){
		pri = (pri+1)%MAX;
		tam--;
	}
	return fila[ (pri-1 + MAX) % MAX]; // vai ficar a cargo do programa principal detectar o erro.
}

/*
// Adiciona um elemento
void add(Elemento e){
	if(tam<MAX){
		fila[ult] = e;
		ult++;
		if(ult%MAX == tam%MAX) // O vetor chegou ao fim! Vamos tentar reaproveitar o começo :P
			if(pri == 0) // Não dá! A lista está cheia :(
				printf("\nErro!! Tentativa de inserir um Elemento no Conjunto cheio!\n");
			else // Reaproveitar! \o/
				tam = 0;
}
// Remove e retorna um Elemento
Elemento rm(void){
	if(pri==ult) // Essa Fila está cheia!
		return; // vai ficar a cargo do programa principal detectar o erro.
	else{
		pri++;
		if(pri==MAX)
			pri = 0;
		
		return fila[pri];
	
		return fila[pri-1];
	}
}
*/

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
		escrever(fila[pos(i)]);
		printf("\n");
	}
}
