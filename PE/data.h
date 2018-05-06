typedef struct{
	char campo1;
	int campo2;
	double campo3; // float maior
} Elemento;

// Carrega os dados de data.bin, se houver; senão, cria um conjunto vazio
void init(void);

// Cria um conjunto vazio
void new(void);

// Ler um Elemento
Elemento ler(void);

// Escrever um Elemento
void escrever(Elemento e);

// Adiciona um elemento
void add(Elemento e);

// Conta os elementos
int count(void);

// Exibe todos os elementos, sem alterar a estrutura
void view(void);

// Remove e retorna um Elemento
Elemento remove(void);

// Sobrescreve o arquivo data.bin com o conteúdo da lista
void save(void);

// Libera a memória do conjunto, para encerrar o programa
void close(void);
