#include <stdbool.h>

typedef struct{
	char campo1;
	int campo2;
	double campo3; // float maior
} Elemento;


// Ler um Elemento
Elemento ler(void);
// Escrever um Elemento
void escrever(Elemento e);


// Cria um conjunto vazio
void new(void);
// Carrega os dados de data.bin, se houver; senão, cria um conjunto vazio
void init(void);
// Sobrescreve o arquivo data.bin com o conteúdo da lista; retorna se a operacao teve erros.
bool save(void);
// Libera a memória do conjunto, para encerrar o programa
void close(void);


// Adiciona um elemento
void add(Elemento e);
// Remove e retorna um Elemento
Elemento rm(void);


// Conta os elementos
int count(void);
// Informa o máximo de elementos que o Conjunto pode guardar. 0 significa sem limite.
int max(void);
// Exibe todos os elementos, sem alterar a estrutura
void view(void);
