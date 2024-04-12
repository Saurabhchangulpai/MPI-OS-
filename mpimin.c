#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define arr_size 1000
#include<limits.h>
int main()
{
	MPI_Init(NULL,NULL);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int ele_per_pro=arr_size/size;
	int num[ele_per_pro];
	int min=INT_MAX;
	srand(rank);
	for(int i=0;i<ele_per_pro;i++)
	{
		num[i]=rand()%1000;
		if(min>num[i])
			min=num[i];
	}
	int gmin;
	MPI_Reduce(&min,&gmin,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);
	printf("Min = %d",gmin);
}