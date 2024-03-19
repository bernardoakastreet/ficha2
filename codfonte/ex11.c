#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>


void func1(int *d){
	++d[0];
	printf("Novo valor gerado em func1: %d\n", d[0]);
	sleep(2);
}

void func2(int *d){
	sleep(1);
	printf("Valor processado por func2: %d\n", d[0]);
}




int main(int argc, char **argv){

	int dados = 0;
	pid_t r;

	while(1){

		func1(&dados);

		r = fork();
		if(!r){

			func2(&dados);
			exit(0);
		}
		wait(NULL);
	}

	return(0);
}
