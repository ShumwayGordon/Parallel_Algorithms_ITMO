#include <stdio.h>
#include <iostream>
#include "mpi.h"
using namespace std;
int main(int argc, char **argv)
{
	int rank;
	MPI_Init(&argc, &argv);
	MPI_File fh;
	char buf[20];
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_File_open(MPI_COMM_WORLD, "file1.txt", MPI_MODE_RDONLY, MPI_INFO_NULL, &fh);
	MPI_File_set_view(fh, rank * 20, MPI_CHAR, MPI_CHAR, "native", MPI_INFO_NULL);
	MPI_File_read_all(fh, buf, 20, MPI_CHAR, MPI_STATUS_IGNORE);
	cout << "process " << rank << ", buf= ";
	for (int i = 0; i < 20; i++)
		printf("%c", buf[i]);
	printf("\n");
	MPI_File_close(&fh);
	MPI_Finalize();
}