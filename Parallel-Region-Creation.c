#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

int main (int argc, char *argv[])
{

	printf("Le nombre de threads  %d\n",  omp_get_num_threads());
	#pragma omp parallel
	{
		printf("Je suis le thread numero %d\n",  omp_get_thread_num());
	}

	return 0;

}
