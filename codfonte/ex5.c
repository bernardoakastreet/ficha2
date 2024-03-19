#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){

	char *ptr = malloc(8);
	strcpy(ptr, "pai");

	pid_t r = fork();

	//Processo filho
	if(!r){
		strcpy(ptr, "filho");
		printf("%s\n", ptr);
		exit(0);
	}

	waitpid(r, NULL, 0);

	printf("%s\n", ptr);
}

/*

É esperado que seja escrito a string "pai" no processo pai e "filho" no processo filho, dado os processos não partilharem qualquer tipo de memória

*/
