// sum of n numbers using for reduction
#include<omp.h>
#include <stdio.h>
#define NUM_THREADS 2
double sum=0.0;
int n = 600000;

int main(int *argc,char *argv[]){
	int nthreads;
	omp_set_num_threads(NUM_THREADS);
	#pragma omp parallel{
		int id;
		id = omp_get_thread_num();
		if (id == 0){
			nthreads = omp_get_num_threads();
			}
		#pragma omp for reduction(+:sum)
		for (int i = 1; i <= n; ++i){
				sum+=1;
		}
	}
	printf(“\nsum = %lf”,sum);
}	