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
		system("ps j");
	}

	return(0);
}
