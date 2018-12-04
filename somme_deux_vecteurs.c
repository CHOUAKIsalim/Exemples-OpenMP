#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#define tailleTableau 100000000	

double *tableau1 ;
double *tableau2 ;
double *sum;



void remplireTableaux()
{
	for(long i=0; i<tailleTableau; i++)
	{
		tableau1[i] = i;
		tableau2[i] = i;
	}
}


int main (int argc, char *argv[])
{
	tableau1 = malloc(tailleTableau * sizeof(double)) ;
	tableau2 = malloc(tailleTableau * sizeof(double)) ;
																																	sum = malloc(tailleTableau * sizeof(double));

	int nb_threads = omp_get_num_threads();
	double debut,fin;	
	remplireTableaux();
	debut = omp_get_wtime();
	#pragma omp parallel for
	for (long i=0; i<tailleTableau ; i++) 
	{
		sum[i] = tableau1[i] + tableau2[i];
	}	 	
	fin = omp_get_wtime();

	printf("Parallel : %lf\n",fin-debut);	
	debut = omp_get_wtime();
	for (long i=0; i<tailleTableau ; i++) 
	{
		sum[i] = tableau1[i] + tableau2[i];
	}	 	
	fin = omp_get_wtime();
	printf("Sequentiel : %lf\n",fin-debut);	


	return 0;

}
