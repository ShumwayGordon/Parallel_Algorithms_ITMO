/*
#include <cstdlib>
#include <iostream>
#include "mpi.h"

int main(int argc, char **argv)
{
	int rank, size;
	
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//matrix initialization by each process
	int N = 500;
	int** a = (int**)malloc(sizeof(int) * N);
	int** b = (int**)malloc(sizeof(int) * N);
	int** c = (int**)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * N);
		b[i] = (int*)malloc(sizeof(int) * N);
		c[i] = (int*)malloc(sizeof(int) * N);
	}

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			a[i][j] = rand() % 100;
			b[i][j] = rand() % 100;
			c[i][j] = 0;
		}

	MPI_Barrier(MPI_COMM_WORLD); //barrier process synchronization
// start timing for each process
	double start_time = MPI_Wtime();

// matrix multiplication
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];

// end of timing
// output the execution time of matrix multiplication at each process
	
	printf("Rank #%d ex time = %lf s\n", rank, MPI_Wtime() - start_time);

	for (int i = 0; i < N; i++)
	{
		free(a[i]);	free(b[i]);	free(c[i]);
	}
	free(a); free(b); free(c);

	MPI_Finalize();
	return 0;
}
*/