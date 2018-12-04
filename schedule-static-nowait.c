#include <stdio.h>
#define SIZE 100


int main() 
{
	double a[SIZE], b[SIZE], c[SIZE], d[SIZE];

	for (size_t i = 0; i < SIZE; i++)   a[i] = b[i] = i;
	#pragma omp parallel
	{
		#pragma omp for schedule(static) nowait
		for (size_t i = 0; i < SIZE; i++) c[i] = a[i] + b[i];
		#pragma omp for schedule(guided)
		for (size_t i = 0; i < SIZE; i++) d[i] = a[i] + c[i];
	}
	for (size_t i = 0; i < SIZE; i++) printf("%g ", d[i]);
	printf("\n");
	return 0;

}

//1- les resultats sont coherents 
//2-  de 0 a 24 => thread 0 
//    de 25 a 49 => thread 1
//    de 50 a 74 => thread 2
//    de 75 a 99 => thread 3

//3- L'utilisation de nowait est raisonnable 

//5- Les resultats ne sont pas coherents avec guided
