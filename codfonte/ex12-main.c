#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h> 
#include <float.h>
#include <unistd.h>
#include <sys/wait.h>

//NELEM must be a multiple of 2
#define NELEM 20000000
#define NITER 50
#define NUMPROC 30

void rectangular2polar(double *, double *, int); 
double mytime();

int main() { 
  double t0;
  pid_t r[30];

  double *dados_in = (double *) malloc(sizeof(double)*NELEM); 
  double *dados_out = (double *) malloc(sizeof(double)*NELEM);
  if(dados_in == NULL || dados_out == NULL) { 
    perror("malloc"); 
    exit(1); 
  } else {
    //assign random initial values
    double maxv = DBL_MAX;
    srand48(time(NULL));
    for(int i = 0; i < NELEM; ++i)
      dados_in[i] = 2*(drand48()-0.5)*maxv;
  }

  //get current time, for benchmarking 
  t0 = mytime();   

  //This cycle is used only for benchmarking purposes
  for(int i=0; i < NITER; ++i){
	for(int j = 0; j < NUMPROC; j++){
		r[j] = fork();
		if(!r[j]){
			rectangular2polar((dados_out + (j*NELEM/NUMPROC)), (dados_in + (j * NELEM/NUMPROC)), NELEM/NUMPROC);
			exit(0);
		}
	}

	for(int l = 0; l < NUMPROC; l++) waitpid(r[l], NULL, 0);
  }
  
  printf("Computation took %.1f s\n", mytime() - t0);
 
  system("lscpu");

  return 0; 
} 

double mytime() {
  struct timeval tp;
  struct timezone tzp;

  gettimeofday(&tp,&tzp);
  return ( (double) tp.tv_sec + (double) tp.tv_usec * 1.e-6 );
}

/*
No caso do computador utilizado, este possui 4 núcleos e 8 threads, o que resultou numa diminuição do tempo de execução de 9.9s para 2.4s.
*/
