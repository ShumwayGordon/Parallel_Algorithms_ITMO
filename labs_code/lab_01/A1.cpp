#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <time.h>
#include "omp.h"


int main(int argc, char* argv[])
{
    unsigned int N; // Number of Elements
    if ( argc == 1 )
    {
        printf("TEST MODE\n");
        N = 100000000;
    }
    else if ( argc == 2 )
    {
        N = atoi( argv[1] );
    }
    else
    {
        printf("Wrong number of parameters. Must be 1.");
        return 1;
    }

    int threads_num = 10;

    // Generating random vector of size N
    std::srand(unsigned(std::time(nullptr)));
    std::vector<double> v(N);
    std::generate(v.begin(), v.end(), std::rand);

    // Creating vector to store found MAX_ELEMENTs and it's index for each thread
    std::vector<double> thread_maxes(threads_num);
    std::vector<int>    thread_max_ids(threads_num);

    

    double max_loc = 0;
    clock_t start = clock();

#pragma omp parallel for num_threads(threads_num) firstprivate(max_loc)
    for (int n = 0; n < N; n++)
    {
        int thread_num = omp_get_thread_num();
        
        if (v[n] > max_loc)
        {
            max_loc = v[n];
            thread_maxes[thread_num] = v[n];
            thread_max_ids[thread_num] = n;
        }
    }

    std::vector<double>::iterator max = std::max_element(thread_maxes.begin(), thread_maxes.end());
    double max_val = *max;
    int max_idx = thread_max_ids[max - thread_maxes.begin()];

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    printf("Number of threads = %d\n", threads_num);

    printf("Execution time: %f ms\n", elapsed*1000);
    
    return 0;
}
