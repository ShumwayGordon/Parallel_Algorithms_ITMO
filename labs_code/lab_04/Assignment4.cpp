/*
#include <iostream>
#include <stdlib.h>
#include "mpi.h"
#include <stdio.h>

using namespace std;
int main(int argc, char* argv[]) {
	MPI_Init(&argc, &argv);
	double time_start = MPI_Wtime();
	int rank, n, i, message;
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD, &n);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int old_message = -1;
	int flag = 1; 

	if (rank == 0)
	{
		cout << "Now is process # " << rank << "\n";
		for (i = 1; i < n; i++) {
			MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE,
			         MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			cout << "Now is process # " << message << endl;
			if (old_message >= message)
				flag = 0;
			old_message = message;
		}
		if (flag)
			printf("Sequence is strictly ascending\n");
		else
			printf("Sequence is NOT strictly ascending\n");
		

	}
	else MPI_Send(&rank, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	printf("Execution time for process # %d = %lf\n", rank, MPI_Wtime() - time_start);
	MPI_Finalize();
	return 0;
}
*/