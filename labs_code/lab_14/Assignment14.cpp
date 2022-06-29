/*
#include <stdio.h>
#include "mpi.h"

void max_gl(void* a, void* b, int* l, MPI_Datatype* type){
	for (int i = 0; i < *l; i++)
		((int*)b)[i] = ((int*)a)[i] > ((int*)b)[i] ? ((int*)a)[i] : ((int*)b)[i];
}

int main(int argc, char **argv)
{
	int rank, size, i;
	int max_val = -1;
	MPI_Init(&argc, &argv);
	MPI_Op op;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Op_create(&max_gl, 1, &op);
	MPI_Reduce(&rank, &max_val, 1, MPI_INT, op , 0, MPI_COMM_WORLD);
	MPI_Op_free(&op);
	if (rank == 0) printf("max_gl max val = %d\n", max_val);
	MPI_Reduce(&rank, &max_val, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
	if (rank == 0) printf("reduce_max max val = %d\n", max_val);
	MPI_Finalize();
	return 0;
}
*/