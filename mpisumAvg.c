#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#define arr_size 1000

int main() {
    MPI_Init(NULL,NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    int ele_per_pro = arr_size / size;
    int local_num[ele_per_pro]; // Statically allocated array
    srand(rank);
    for (int i = 0; i < ele_per_pro; i++) {
        local_num[i] = rand() % 1000;
    }
    int local_sum = 0;
    for (int i = 0; i < ele_per_pro; i++) {
        local_sum += local_num[i];
    }
    int global_sum;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        double avg = (double)global_sum / arr_size;
        printf("Sum = %d\n", global_sum);
        printf("Avg = %lf\n", avg);
    }
    MPI_Finalize();
    return 0;
}

