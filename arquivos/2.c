// Questão 2, Lista 5 - Simone (Arquivo)
#include <stdio.h>

typedef struct{
	char nome[50];
	char sobrenome[50];
	int idade;
}Pessoa;

Pessoa lePessoa(FILE *f){
	Pessoa p;
	
	fscanf(f, "%s", p.nome);
	fscanf(f, "%s", p.sobrenome);
	fscanf(f, "%d", &p.idade);
	
	return p;
}

void imprimePessoa(Pessoa p, FILE *f){
	if(feof(f))
		return;
	else
		printf("%s %s|%d\n", p.nome, p.sobrenome, p.idade); 
}

int main(void){
	FILE *f = fopen("nomes.txt","r");
	
	while(!feof(f)){
		imprimePessoa( lePessoa(f), f );
	}
	
	fclose(f);
}
