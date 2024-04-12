#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>
#define arr_size 1000
int main()
{
	MPI_Init(NULL,NULL);
	int rank,size;
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int ele_per_pro=arr_size /size;
	int num[ele_per_pro];
	int sum=0;
	srand(rank);
	int avg=0;
	for(int i=0;i<ele_per_pro;i++)
	{
		num[i]=rand()%arr_size;
		sum+=num[i];
	}
	int gsum;
	MPI_Reduce(&sum,&gsum,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);
	avg=sum/arr_size*size;
	printf("\nGsum= %d",gsum);
	printf("\navg= %d",avg);
	printf("\nSum =%d",sum);
	MPI_Finalize();
	return 0;
}
