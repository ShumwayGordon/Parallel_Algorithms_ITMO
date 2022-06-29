/*
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "mpi.h"
using namespace std;
int main(int argc, char **argv)
{
	int rank, recv_msg;
	int message = 42;
	MPI_Init(&argc, &argv);
	char port_name[MPI_MAX_PORT_NAME];
	MPI_Status status;
	MPI_Comm intercomm;
	strcpy(port_name, argv[1]);

	MPI_Comm_connect(port_name, MPI_INFO_NULL, 0, MPI_COMM_SELF, &intercomm);
	//printf("Client connected\n");
	cout << "Client connected" << endl;

	MPI_Send(&message, 1, MPI_INT, 0, 0, intercomm);
	//printf("Client sent: %d\n", message);
	cout << "Client sent: " << message << endl;

	MPI_Recv(&recv_msg, 1, MPI_INT, 0, 0, intercomm, &status);
	//printf("Client recieved: %d\n", recv_msg);
	cout << "Client recieved: " << recv_msg << endl;

	MPI_Finalize();
	return 0;
}
*/