#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<mpi.h>
#define arr_size 1000
int main()
{
	MPI_Init(NULL,NULL);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int ele_per_pro=arr_size/size;
	int num[ele_per_pro];
	int max=INT_MIN;
	srand(rank);
	for(int i=1;i<=ele_per_pro;i++)
	{
		num[i]=rand()%arr_size;
		if(max<num[i])
			max=num[i];
	}
	int gmax;
	MPI_Reduce(&max,&gmax,1,MPI_INT,MPI_MAX,0,MPI_COMM_WORLD);
	printf("Gmax =%d",gmax);
	MPI_Finalize();
	return 0;
}
