#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char **argv){

	pid_t r;

	r = fork();

	if(!r){

		printf("Processo filho: %d\n\nProcesso Pai: %d\n\n", getpid(), getppid());
		exit(0);
	}

	sleep(3);
	system("ps -f");
	printf("\n\nProcesso Pai vai terminar\n\n");
	return(0);
}

/*
Na primeira impressão na consola, é possível verificar que o processo filho encontra-se defunto, dado ter terminado a sua execução mas não havendo o seu valor de retorno pelo processo pai, ainda a executar. Uma vez terminado o processo pai, o processo filho é atribuido ao sistema, que acaba por ler o seu valor de retorno, saindo assim de defunto.
*/
