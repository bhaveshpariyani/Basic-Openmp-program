// sum of n numbers usinf openmp critical
#include<omp.h>
#include <stdio.h>
#define NUM_THREADS 2
double sum=0.0;
int n = 600000;

int main(int *argc,char *argv[]){
	int nthreads;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel private(lsum){
		int i,id;
		id = omp_get_thread_num();
		if(id == 0) nthreads = omp_get_num_threads();
		#pragma omp for
		for (i=1; i<=n; i++){
			lsum = lsum +1 ;
		}
		#pragma omp critical{
		sum+=lsum;
		}
	}
	printf(“\nsum = %lf”,sum);
}