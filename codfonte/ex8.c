#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	pid_t r;

	printf("Processo inicial: %d\n", getpid());

	r = fork();
	if(!r){
		printf("Novo processo, que irá terminar imediatamente: %d\n", getpid());
		r = fork();
		if(r) exit(0);

		sleep(1);
		printf("\nPID = %d, PPID = %d\n\n", getpid(), getppid());
		sleep(3);
		printf("\nPID = %d, PPID = %d vai terminar\n\n", getpid(), getppid());
		exit(0);
	}

	sleep(2);
	system("ps -f");

	printf("\nChamada à função wait\n\n");

	wait(NULL);
	system("ps -f");
	sleep(2);
	system("ps -f");

	return(0);
}
