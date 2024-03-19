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
	execlp("ps", "ps", "-f", (char *)NULL);
	printf("\n\nProcesso Pai vai terminar\n\n");
	return(0);
}

/*
A função execlp irá substituir o processo pai pela bash. Ao substituir, e como a instrução printf do fim do processo segue-se à instrução execlp, esta primeira nunca é executada, porque o processo termina na instrução execlp.
*/
