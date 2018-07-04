#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int v;
	struct _node *prox;
} Node;

int main(void){
	
	//int *x;
	//printf("%d",x);
	
	Node *pri = NULL;
	pri = malloc(sizeof(Node));
	
	//*(pri).v
	pri->v = 19;
	pri->prox = NULL;
	
	pri->prox = malloc(sizeof(Node));
	pri->prox->v = 23;
	pri->prox->prox = NULL;
	
	Node *aux = pri;
	while(aux != NULL){
		printf("%d\n", aux->v);
		aux = aux->prox;
	}
	
	return 0;
}
