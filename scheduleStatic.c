#include <stdio.h>
#include <omp.h>
#define SIZE 100
#define CHUNK 9


int main()
{
    int tid;  //Par un seul thread
    double a[SIZE], b[SIZE], c[SIZE]; //Par un seul thread
    for (size_t i = 0; i < SIZE; i++) //Par un seul thread
    a[i] = b[i] = 1; //Par un seul thread
    #pragma omp parallel private(tid)
    {
        tid = omp_get_thread_num(); //Par tout les threads
        if (tid == 0) //Par tout les threads  
	printf("Nb threads = %d\n", omp_get_num_threads()); //Par un seul thread
        printf("Thread %d: starting...\n", tid); //Par tout les threads
        #pragma omp for schedule(static, CHUNK)  //Par tout les threads
        for (size_t i = 0; i < SIZE; i++)    
        {
            c[i] = a[i] + b[i];
            printf("Thread %d: c[%2zu] = %g\n", tid, i, c[i]);
        }
    }
    return 0;
}


//Ordre d'execution aléatoire, il change a chaque execution 

//Pour le dynamique la repartition n'est pas stable 

//Pour le static la repartition est stable 
