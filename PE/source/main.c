#include <stdio.h>

#include "programa.h"

int main(void){
	short op;
	
	do{
		menu();
		scanf("%hd", &op); // Half-Decimal
	} while(exec(op));
}
