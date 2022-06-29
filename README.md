# Parallel_Algorithms_ITMO

Laboratory works on the subject "Parallel algorithms for the analysis and synthesis of data" are divided into two groups:
1) 0-2 works are related to the open standard for program parallelization OpenMP
2) the rest of the work is related to the Message Passing Interface (MPI)

## Assignments for labs:


### Assignment 0.

Write a program for counting words in a line. Any sequence of characters without separators is considered a word. Separators are spaces, tabs, newlines. The input string is passed to the program through the terminal as the argv [1] parameter. The program should display the number of words on the screen.


### Assignment 1. OpenMP. Finding the maximum value of a vector

Write a parallel OpenMP program that finds the maximum value of a vector (onedimensional array). Each thread should only store its maximum value; concurrent access to a shared variable that stores the maximum value is not allowed. Study the dependence of the runtime on the number of threads used (from 1 to 10) for a vector that contains at least 1,000,000 elements (the more, the better). Check the correctness of the program on 10 elements. The program should display on the screen: the number of threads, the execution time. Transfer the size of the vector through the argv [1] parameter.


### Assignment 2. OpenMP. Matrix multiplication

Write a program for multiplying two square matrices using OpenMP. Examine the performance of different modifications of the algorithm (different loop order), depending on the number of threads used for matrices of at least 800x800. Check the correctness of the multiplication on 5x5 matrices. Calculate the efficiency by the formula t1 / t and display it, where t1 is the multiplication time on only one stream, t is the multiplication time on n streams (the number of streams is taken from 1 to 10). The program should output number of threads, multiplication time and efficiency. Transfer the size of matrices through the argv[] parameter.


### Assignment 3.

Compile and run Assignment3.c program. Explain in detail how it works


### Assignment 4. MPI.

The root process accepts messages from child processes and determines whether the sequence is strictly ascending.


### Assignment 5. MPI. Determination of the execution time.

Compile and run Assignment5.c program. Explain in detail how it works. Determine the execution time of the program from the previous task.


### Assignment 6. MPI. Retrieving information about the message attributes.

Compile the example Assignment6.c in detail, run it and explain it. Transform the program using the MPI_TAG field of the status structure in the condition.


### Assignment 7. MPI. Dot product of vectors.

Write an MPI program that implements the dot product of two vectors distributed between processes. Two vectors with a size of at least 1,000,000 elements are initialized at process zero and filled with “1”, then they are sent in equal parts to all processes. Parts of vectors are scalar multiplied on each process, the result is sent to the root process and summed up. The total is displayed.


### Assignment 8. MPI. Bandwidth measurement.

Write an MPI program in which two processes exchange messages, measure the time per exchange iteration, and determine the dependence of the exchange time on the message length. Determine the latency and maximum achievable bandwidth of the communication network. Print the message length in bytes and the throughput in MB/s to the console. Change the length of the message in a loop starting from 1 element and increase to 1,000,000 elements, increasing by 10 times at each iteration.


### Assignment 9. MPI. Retrieving information about the message attributes.

Write an MPI program in which the global vector addition operation is modeled by a doubling (cascade) scheme using point-to-point data transfers. Compare the execution time of such a simulation using the MPI_Reduce procedure on as many processes as possible. Each process stores an array of 1,000,000 elements equal to ‘1’. The resulting array is saved, for example, on process 0.


### Assignment 10. MPI. Sending and receiving messages without blocking. Ring exchange using non-blocking operations.

Complete the program Assignment10.c. Compile and run it. Study the code carefully and explain how it works


### Assignment 11. MPI. Combined reception and transmission of messages.

Based on Assignment 10, write a program for ring topology exchange using the MPI_Sendrecv() function. In situations where you need to exchange data between processes, it is safer to use the overlaid MPI_Sendrecv operation. The MPI_Sendrecv function combines the execution of the send and receive operations. Both operations use the same communicator, but message IDs may differ. The location of the received and transmitted data in the address space of the process should not overlap. The data sent can be of different types and lengths. In cases when it is necessary to exchange data of the same type with replacement of the sent data with the received ones, it is more convenient to use the MPI_Sendrecv_replace function. In this operation, the data sent from the buf array is replaced with the received data. The special address MPI_PROC_NULL can be used for source and dest in data transfer operations. Communication operations with such an address do nothing. The use of this address is convenient instead of using logical constructs to analyze the conditions to send / read a message or not.


### Assignment 12. MPI. Delayed interactions. Scheme of an iterative method with exchange over a ring topology using pending requests.

Find and fix errors in Assignment12.c, add the for loop. When should you use a loop?


### Assignment 13. MPI. Collective process interactions. Barrier.

Find out which process will perform the multiplication of two 500x500 square matrices faster. Complete the code Assignment13.c. You can use the necessary code from the previous assignments.


### Assignment 14. MPI. Custom global operations. Custom global function.

Understand the new functions in Assignment14.c. Create your own global function for finding the maximum element, compare the correctness of execution with the MPI_MAX operation in the MPI_Reduce() function.


### Assignment 15. MPI. Operations with communicators. Partitioning the communicator.

Understand the new functions in Assignment15.c. Append part of code.


### Assignment 16. MPI. Operations with communicators. Renumbering processes.

In the MPI_Comm_split function (Assignment16.c), replace the color parameter with (rank% 2), (rank% 3), look at how many groups the processes are split into, depending on the specified attribute of division into groups. The function splits the group associated with the parent communicator into non-overlapping subgroups, one for each value of the color subgroup attribute. Color must be non-negative. Each subgroup contains processes with the same color value. The key parameter controls the ordering within the new groups: a lower key value corresponds to a lower process ID value. If the key parameter is equal for multiple processes, the ordering is performed according to the order in the parent group.


### Assignment 17. MPI. Data packing. Sending packed data.

Understand the new functions in Assignment17.c. and explain program execution. Display the values of the process number and arrays a[i], b[i], before packing and distribution, and after. See how broadcasting works.


### Assignment 18. MPI. Dynamic process control. Spawning processes.

To complete the task, you need to create and compile two programs: Master (master.o) and Slave (slave.o). The Master should start the worker, so be careful with the names of the executable files. Launch the master via the mpiexec command for one process. Startup example: mpiexec  n 1 ./master.o. Understand the new functions in Assignment18_master.c and Assignment18_slave.c and explain programs execution. Add a third process, which will transfer from the slave processes to the master the number of running processes, the master should receive and display.


### Assignment 19. MPI. Dynamic process control. Client-server communication.

To complete the task, you need to create and compile two programs: server and client. In one window of the SSH client, a server is launched for one process, which gives out the port name. An example of a command to start the server: mpiexec -n 1 ./serv.o Then the client is launched in another window, specifying the port name separated by a space in single quotes (example command: mpiexec -n 1 ./client.o ‘port name’). Understand the new functions in Assignment19_serv.c and Assignment19_client.c and explain programs execution. Check the work by running the server and the client. Add the program and send an arbitrary message to each other.


### Assignment 20. MPI. Parallel I / O. Working with files. Access to data. Buffered reading from a file.

Understand the new functions in Assignment20.c, complete the program according to the assignment, explain the execution of the program. Write a function that will create a file "file.txt" with random content (or with specific text). The function must be executed before the program reads the contents of the file. Run the program on one process. Check if the contents of the file are displayed correctly. Add an option that will delete the file on close.


### Assignment 21. MPI. Parallel I / O. Working with files. Access to data. Collective reading from a file.

Understand the new functions in Assignment21.c, complete the program according to the assignment, explain the execution of the program. Create a file and fill it with bulky text, output the content in parallel. Change the step of reading the contents of the file and the number of characters to be output by each process.
