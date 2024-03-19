#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NELEM 20

int main(int argc, char **argv){
	double *dados;
	pid_t r1, r2;

	dados = malloc(NELEM*sizeof(double));
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

O vetor mantém os valores iniciais dado que a função malloc reserva um espaço na memória virtual de cada processo, pelo que o vetor criado pelo processo pai é diferente do vetor criado pelo processo filho.

*/
