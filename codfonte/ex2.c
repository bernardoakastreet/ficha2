int i = 0;

int main(){
	pid_t r = fork();
	if(!r){
		sleep(10);
		printf("%d: %d\n", getpid(), i, r);
		return 0;
	}

	i = i + 1;
	wait(NULL);
	printf("%d: %d %d\n", getpid(), i, r);

	return 0;
}

/*

a) Irá ser executado o printf do processo filho e, após o seu return, será executado o printf do processo pai.

b) O facto deve-se à função wait, executada no processo pai, que irá aguardar pelo valor de retorno do processo filho.

c) A ausência do return na estrutura condicional do filho iria fazer com que o filho continue a execução do código até ao return final, dado não ter processos filho, rapidamente executando a função wait. Posteriormente a função pai iria imprimir a sua função printf.

*/
