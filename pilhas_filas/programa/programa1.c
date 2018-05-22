#include <stdio.h>

#include "programa.h"

Elemento ler(void){
	Elemento retorno;
	
	printf("Digite um caracter: ");
	scanf(" %c", &retorno.campo1);
	
	printf("Digite um inteiro: ");
	scanf("%d", &retorno.campo2);
	
	printf("Digite um numero real: ");
	scanf("%lf", &retorno.campo3);
	
	return retorno;
}

void escrever(Elemento e){
	printf("\tCampo 1: %c\n", e.campo1);
	
	printf("\tCampo 2: %d\n", e.campo2);
	
	printf("\tCampo 3: %lf\n", e.campo3);
}

//#define tamSeparador 24
void printSeparador(short tam){
	int i;
	for(i=0; i<tam; i++)
		printf("-");
	printf("\n");
}

void menu(void){
	printf("\n");
	printf("Digite uma opcao:\n\n");
	printf("0 - Comecar um novo Conjunto, vazio;\n");
	printf("1 - Inserir novo elemento;\n");
	printf("2 - Obter (e remover) elemento;\n");
	printf("3 - Exibir todos os elementos;\n");
	printf("4 - Salvar Conjunto atual;\n");
	printf("5 - Salvar Conjunto atual e encerrar;\n");
	//printf(";\n");
	printf("6 - Descartar Conjunto atual e encerrar.\n");
	printf("\n> ");
}

bool exec(short op){
	printf("\n");
	
	switch(op){
		case 0:
			if(count()==0);
			else{
				// Chaves para definir novo escopo, e poder declarar essa var, que soh faz sentido aqui
				char resposta;
			
				printf("Voce tem certeza que deseja descartar todas as modificacoes realizadas no Conjunto?\n");
				printf("Digite \"s\": ");
				scanf(" %c", &resposta);
			
				if(resposta == 's'){
					printf("\n");
					new();
				}
			}
			
			break;
			
		case 1:
			if(max())
				if(count() >= max()){
					printSeparador(28);
					printf("\n  O Conjunto esta cheio!\n");
					printSeparador(28);
					break;
				}
			add(ler());
			break;
			
		case 2:
			
			if(count()>0){
				printSeparador(28);
				printf("  O elemento removido foi:\n");
				escrever(rm());
				printSeparador(28);
			}
			else{
				printSeparador(30);
				printf("  O Conjunto jah esta vazio!\n");
				printSeparador(30);
			}
			
			break;
			
		case 3:
			view();
			break;
			
		// Executar em ambos
		case 4:
			if(save()){ // Se houveram erros
				printSeparador(19);
				printf("  Erro ao salvar!\n");
				printSeparador(19);
			}
			break;
			
		case 5:
			if(save()){ // Se houveram erros
				printSeparador(19);
				printf("  Erro ao salvar!\n");
				printSeparador(19);
			}
			else
				return false; // Só encerra se salvou com sucesso
			break;
			
		case 6:
			{
				// Chaves para definir novo escopo, e poder declarar essa var, que soh faz sentido aqui
				char resposta;
			
				printf("Voce tem certeza que deseja descartar todas as modificacoes realizadas no Conjunto?\n");
				printf("Digite \"s\": ");
				scanf(" %c", &resposta);
			
				if(resposta == 's'){
					printf("\n");
					return false;
				}
			}
				
			break;
		
		default:
			printSeparador(19);
			printf("  Opcao invalida!\n");
			printSeparador(19);
	}
	
	return true;
}
