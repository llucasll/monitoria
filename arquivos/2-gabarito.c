
#include <stdio.h> 
#include <stdlib.h> 
int main() 
{ 
    char nome[30], narq[30]; 
    FILE *arq; 
    int idade,n, Fimarq=0; 
    gets(narq); 
    if ((arq = fopen(narq, "r")) == NULL) 
    { 
          printf("\n Erro: Nao e possivel abrir %s!!", narq); 
          exit(1); 
    } 
    if (fgets(nome,"%s\n",arq)==NULL) 
        Fimarq=1; 
    while (!Fimarq) 
    { 
      if (fscanf(arq,"%d\n",&idade)> 0) { 
        n=strlen(nome); 
        if (nome[n-1]=='\n') nome[n-1]='\0'; 
        printf("Nome: %s | %d\n",nome,idade); 
        if (fgets(nome,"%s\n",arq)==NULL) 
            Fimarq=1; 
      } 
     else Fimarq=1; 
    } 
    fclose(arq); 
}
