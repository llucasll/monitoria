mensagem:
	@echo
	@echo ESCOLHA UMA DAS ESTRUTURAS \(EM \"estruturasDeDados\/\", SEM A EXTENSÃO\)\:
	@echo
	@echo | ls -1 estruturasDeDados
	@echo
	@echo Exemplo\: $ make a-fila
	@echo
	
exec:
	#$@
	@echo
	
%:
	gcc -o exe.out programa/*.c estruturasDeDados/$@.c
	./exe.out
	
clean:
	rm -rf `find  -name '*~'; find -name '*.o'; find -name '*.out'`
	@echo
	
clear: clean
	@
	
limpa: clean
	@
	
limpar: clean
	@

