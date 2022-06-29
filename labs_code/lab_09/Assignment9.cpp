/*
#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char** argv)
{
	int rank, size, sum;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;
	int N = 1000000;
	int loc_sum = 0;
	int *arr = (int*)malloc(sizeof(int)*N); 
	for( int i = 0; i < N; i++ )
		arr[i] = 1;

	double start_time = MPI_Wtime();
	for (int i = 0; i < N; i++)
		loc_sum += arr[i];

	if (rank != 0)
	{
		for (int i = 1; i < (size - 1) / 2; i++)
		{
			if (rank % (2 * i) == 0)
			{
				int rec_sum;
				MPI_Recv(&rec_sum, 1, MPI_INT, MPI_ANY_SOURCE,
						 MPI_ANY_TAG, MPI_COMM_WORLD, &status);
				loc_sum = rec_sum;
			}
			else
			{
				MPI_Send(&loc_sum, 1, MPI_INT, rank + pow(2,i-1), 
						 0, MPI_COMM_WORLD);
				break;
			}
		}
	}
	if( rank == size - 1 )
		MPI_Send(&loc_sum, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);

	if (rank == 0)
	{
		int rec_sum = 0;
		MPI_Recv(&rec_sum, 1, MPI_INT, MPI_ANY_SOURCE, 1, 
				 MPI_COMM_WORLD, &status);		
		printf("\nSum point-2-point = %d\n", rec_sum);
		printf("Time point-2-point = %lf s\n\n", MPI_Wtime() - start_time);
	}

	loc_sum = 0;
	start_time = MPI_Wtime();
	for (int i = 0; i < round(N / size); i++) 
		loc_sum += arr[i];

	MPI_Reduce(&loc_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
		printf("Reduce sum = %d\nReduce time = %lf\n", 
			   sum, MPI_Wtime() - start_time);

	free(arr);
	MPI_Finalize();
	return 0;
}
*/