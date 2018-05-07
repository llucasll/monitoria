mensagem:
	@echo
	@echo Informe também qual dos arquivos contidos em estruturasDeDados você deseja utilizar \(sem a extensão\)
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

