#include<stdio.h>
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
	srand(rank);
	int sum=0;
	for(int i=0;i<ele_per_pro;i++)
	{
		num[i]=rand()%1000;
		if((num[i]%2)==0)
		{
			sum+=num[i];
		}
	}
	int gsum;
	MPI_Reduce(&sum,&gsum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	printf("Sum of even numbers = %d",gsum);
	MPI_Finalize();
	return 0;
}
