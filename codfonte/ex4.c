#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define NELEM 20

void *shmalloc(size_t size){
	return mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
}


int main(int argc, char **argv){
	double *dados;
	pid_t r1, r2;

	dados = shmalloc(NELEM*sizeof(double));
	for(int i = 0; i < NELEM; i++) dados[i] = i;

	r1 = fork();

	if(!r1){
		for(int i = 0; i < NELEM/2; i++) dados[i] = dados[i] * 2.0;
		exit(0);
	}

	r2 = fork();

	if(!r2){
		for(int i = NELEM/2; i < NELEM; i++) dados[i] = dados[i] * 2.0;
		exit(0);
	}

	waitpid(r1, NULL, 0);
	waitpid(r2, NULL, 0);

	for(int i = 0; i < NELEM; i++) printf("%f ", dados[i]);

	printf("\n");

	return(0);
}

/*

Como a função shmalloc reserva espaço na memória partilhada, o processo pai consegue aceder a essa memória e verificar as alterações realizadas pelos processos filho.

*/
