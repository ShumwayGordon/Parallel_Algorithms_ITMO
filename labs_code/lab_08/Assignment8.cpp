#include <iostream>
#include <mpi.h>
using namespace std;
typedef unsigned int uint;

int main(int argc, char** argv)
{
	int rank, size;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Status status;

	if (rank == 0 || rank == 1)
	{
		for (int i = 1; i <= 1000000; i *= 10)
		{
			int *arr = (int*)malloc(sizeof(int) * i);
			for (int k = 0; k < i; k++)
				arr[k] = 1;

			double time_start, ex_time;
			if (rank == 0)
				ex_time = 0;

			for (int j = 0; j < 10; j++)
			{
				if (rank == 0)
				{
					time_start = MPI_Wtime();
					MPI_Send(arr, i, MPI_INT, 1, 0, MPI_COMM_WORLD);
					MPI_Recv(arr, i, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
					ex_time += MPI_Wtime() - time_start;
				}
				else if (rank == 1)
				{
					MPI_Recv(arr, i, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
					MPI_Send(arr, i, MPI_INT, 0, 0, MPI_COMM_WORLD);
				}
			}
			if( rank == 0 )
				printf("Length of message on cur iteration L = %lf MB\nExecution time T = %lf s\nBandwidth R = %lf GB/s\n\n", 
					double(i * int(sizeof(int))) / (1024.0 * 1024.0),  ex_time, (double(2 * 10 * i * int(sizeof(int))) / (1024.0 * 1024.0 * 1024.0)) / ex_time);
			free(arr);
		}

		int* arr = (int*)malloc(sizeof(int) * 0);
		double time_start, ex_time_2;
		if(rank == 0)
			ex_time_2 = 0;

		for (int j = 0; j < 10; j++)
		{
			if (rank == 0)
			{
				time_start = MPI_Wtime();
				MPI_Send(arr, 0, MPI_INT, 1, 0, MPI_COMM_WORLD);
				MPI_Recv(arr, 0, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
				ex_time_2 += MPI_Wtime() - time_start;
			}
			else if (rank == 1)
			{
				MPI_Recv(arr, 0, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
				MPI_Send(arr, 0, MPI_INT, 0, 0, MPI_COMM_WORLD);
			}
		}
		if (rank == 0)
			printf("Latency s = %lf s\n\n", ex_time_2/( 2.0 * 10.0 ));
		free(arr);
	}
	MPI_Finalize();
	return 0;
}
