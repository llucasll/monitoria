Elemento ler(void){
	Elemento retorno;
	
	printf("Digite um caracter: ");
	scanf("%c", &retorno.campo1);
	
	printf("Digite um inteiro: ");
	scanf("%d", &retorno.campo2);
	
	printf("Digite um numero real: ");
	scanf("%lf", &retorno.campo3);
	
	return retorno;
}

void escrever(Elemento e){
	printf("\tCampo 1: %c", e.campo1);
	
	printf("\tCampo 2: %d", e.campo2);
	
	printf("\tCampo 3: %lf", e.campo3);
}

void exec(void){
	short op=0;	
	
	while(op != 6){
		printf("Digite uma opcao:\n");
		printf("0 - Comecar um Conjunto vazio;\n");
		printf("1 - Inserir novo elemento;\n");
		printf("2 - Obter (e remover) elemento;\n");
		printf("3 - Exibir todos os elementos;\n");
		printf("4 - Salvar Conjunto atual;\n");
		printf("5 - Salvar Conjunto atual e encerrar;\n");
		printf(";\n");
		printf("6 - Descartar Conjunto atual e encerrar.\n");
		printf("\n> ");
		
		scanf("%d", &op);
		printf("\n");
		
		switch(op){
			case 0:
				new();
				break;
				
			case 1:
				add(ler());
				break;
				
			case 2:
				printf("\n\n\tO elemento removido foi:\n");
				escrever(remove());
				break;
				
			case 3:
				view();
				break;
				
			// Executar em ambos
			case 4:
				save();
				break;
				
			case 5:
				save();
				op = 6;
				break;
			
			// Não precisa do caso 6, vai ser testado no while e vai encerrar.
			
			default:
				printf("Opcao invalida!\n");
		}
	}
}
