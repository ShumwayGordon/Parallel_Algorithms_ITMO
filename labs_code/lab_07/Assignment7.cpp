#include <iostream>
#include <mpi.h>
using namespace std;

int main( int argc, char** argv )
{
	int rank, size, part_size, arr_len;
	int root_proc = 0;
	if (argc == 1)
	{
		printf("TEST MODE\n\n");
		arr_len = 1000000;
	}
	else if (argc == 2)
		arr_len = atoi(argv[1]);
	else
	{
		printf("Wrong number of parameters. Must be 1.");
		return 1;
	}
	
	MPI_Init(&argc, &argv);
	int *arr_1 = nullptr;
	int *arr_2 = nullptr;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	part_size = arr_len / size;

	if (rank == root_proc)
	{
		arr_1 = (int*)malloc(sizeof(int) * arr_len);
		arr_2 = (int*)malloc(sizeof(int) * arr_len);

		for (int i = 0; i < arr_len; i++)
		{
			arr_1[i] = 1;
			arr_2[i] = 1;
		}
	}

	int* part_arr_1 = (int*)malloc(sizeof(int) * part_size);
	int* part_arr_2 = (int*)malloc(sizeof(int) * part_size);

	MPI_Scatter(arr_1, part_size, MPI_INT, part_arr_1, part_size, MPI_INT, root_proc, MPI_COMM_WORLD);
	MPI_Scatter(arr_2, part_size, MPI_INT, part_arr_2, part_size, MPI_INT, root_proc, MPI_COMM_WORLD);

	int loc_sum = 0;
	for(int i = 0; i < part_size; i++)
		loc_sum += part_arr_1[i] * part_arr_2[i];

	int sum;

	MPI_Reduce(&loc_sum, &sum, 1, MPI_INT, MPI_SUM, root_proc, MPI_COMM_WORLD);

	if (rank == root_proc)
		printf("Dot product = %i\n", sum);

	free(part_arr_1);
	free(part_arr_2);
	if (rank == root_proc)
	{
		free(arr_1);
		free(arr_2);
	}

	MPI_Finalize();
	return 0;
}
