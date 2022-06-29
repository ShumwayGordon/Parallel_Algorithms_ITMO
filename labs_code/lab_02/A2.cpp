#include <iostream>
#include <omp.h>

typedef unsigned int uint;

void generate_matrix( uint **array, uint n )
{
	for (uint i = 0; i < n; i++)
	{
		for (uint j = 0; j < n; j++)
		{
			array[i][j] = rand() % 100;
			//printf("%d ", array[i][j]);
		}
		//printf("\n");
	}
	//printf("\n");
}


double matrix_mult_serial( uint **a, uint**b, uint **c, uint n )
{
	double st = omp_get_wtime();
	for (uint i = 0; i < n; i++)
	{
		for (uint j = 0; j < n; j++)
		{
			for (uint k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			//printf("%d ", c[i][j]);
		}
		//printf("\n");
	}
	double en = omp_get_wtime();
	printf("Execution time Serial: %lf\n", en - st);

	return(en - st);
}


double matrix_mult_parallel1( uint** a, uint** b, uint** d, uint n, int threads_num )
{
	double st = omp_get_wtime();
	int i, j, k;
#pragma omp parallel for num_threads(threads_num) private(i,j,k) shared(a,b,d)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (k = 0; k < n; k++)
					d[i][j] += a[i][k] * b[k][j];
	/*
	for (uint i = 0; i < n; i++)
	{   for (uint j = 0; j < n; j++)
			printf("%i ", d[i][j]);
		printf("\n");	}
	*/
	double en = omp_get_wtime();
	printf("Execution time Parallel_1 = %lf s\n", en - st);

	return (en - st);
}


double matrix_mult_parallel2( uint **a, uint **b, uint **d, uint n, int threads_num)
{
	double st = omp_get_wtime();
	int i, j, k;
#pragma omp parallel for num_threads(threads_num) private(i,j,k) shared(a,b,d)
		for (i = 0; i < n; i++)
			for (k = 0; k < n; k++)
				for (j = 0; j < n; j++)
					d[i][j] += a[i][k] * b[k][j];
	/*
	for (uint i = 0; i < n; i++)
	{
		for (uint j = 0; j < n; j++)
			printf("%i ", d[i][j]);
		printf("\n");
	}
	*/
	double en = omp_get_wtime();
	printf("Execution time Parallel_2 = %lf s\n", en - st);

	return(en - st);
}


int main( int argc, char* argv[] )
{
	uint N; // Size of square matrix
	if ( argc == 1 )
	{
		printf("TEST MODE\n\n");
		N = 800;
	}
	else if ( argc == 2 )
		N = atoi(argv[1]);
	else
	{
		printf("Wrong number of parameters. Must be 1.");
		return 1;
	}

	// Setting the number of threads
	uint threads_num = 1;
	printf("Threads Number = %d\n\n", threads_num);

	// Allocating memory for matrices
	uint **a = (uint**)malloc(sizeof(uint) * N);
	uint **b = (uint**)malloc(sizeof(uint) * N);
	uint **c = (uint**)malloc(sizeof(uint) * N);
	uint **d = (uint**)malloc(sizeof(uint) * N);
	uint **e = (uint**)malloc(sizeof(uint) * N);

	// Allocating memory for therads time
	double *time_par_1 = (double*)malloc(sizeof(double) * threads_num);
	double* time_par_2 = (double*)malloc(sizeof(double) * threads_num);

	for (uint i = 0; i < N; i++)
	{
		a[i] = (uint*)malloc(sizeof(uint) * N);
		b[i] = (uint*)malloc(sizeof(uint) * N);
		c[i] = (uint*)malloc(sizeof(uint) * N);
		d[i] = (uint*)malloc(sizeof(uint) * N);
		e[i] = (uint*)malloc(sizeof(uint) * N);
	}
	
	// Generating random matrices a and b
	generate_matrix(a, N);
	generate_matrix(b, N);

	// Initializing resulting matrices with 0-s
	for (uint i = 0; i < N; i++)
		for (uint j = 0; j < N; j++)
		{
			c[i][j] = 0;
			d[i][j] = 0;
			e[i][j] = 0;
		}

	// Computing multiplication
	double ser_t = matrix_mult_serial( a, b, c, N );
	double par_1_t = matrix_mult_parallel1( a, b, d, N, threads_num );
	double par_2_t = matrix_mult_parallel2( a, b, e, N, threads_num );

	printf("\nEfficiency for Parallel_1 = %lf\n", ser_t / par_1_t);
	printf("Efficiency for Parallel_2 = %lf\n", ser_t / par_2_t);
	
	// Freeing up the memory
	for (uint i = 0; i < N; i++)
	{
		free(a[i]);	free(b[i]);	free(c[i]); free(d[i]); free(e[i]);
	}
	free(a); free(b); free(c); free(d); free(e);
	free(time_par_1); free(time_par_2);
	return 0;
}

