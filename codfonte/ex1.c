#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv){
	pid_t r;

	printf("\nProcesso %d a executar %s\n\n", getpid(), argv[0]);

	r = fork();

	printf("Valor de retorno da função fork para o processo %d: %d\n\n", getpid(), r);

	if(!r){
		for(int i = 0; i < 10; i++){
			sleep(1);
			printf("Novo processo, com PID = %d (\"filho\" de %d)\n", getpid(), getppid());
		}
		exit(0);
	}

	for(int i = 0; i < 10; i++){
		sleep(2);
		printf("Processo inicial (PID = %d, \"filho\" de %d).\n", getpid(), getppid());
	}

	return(0);
}


/*

b) O valor de retorno do processo pai da função fork é 651, o PID do processo filho criado.

c) A função printf é executada duas vezes porque, após a função fork, o processo filho criado mantém tudo do processo pai. Dado que a função é chamada sem qualquer condição acerca do processo que a deve executar, ambos os processos (pai e filho) executam a linha de código.

d) O processo pai do processo cirado para iniciar a execução do programa é a bash (terminal Linux)

e) O processo filho irá continuar a executar o código (linha 25)

*/
