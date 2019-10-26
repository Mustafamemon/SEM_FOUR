#include<stdio.h>
#include<stdlib.h>
float SJF_W(int n , float *burst)
{
	int i,j;
	float AvgWaiting=0,*burst1=(float *)malloc(n*sizeof(float));
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			if(burst[i]>burst[i+1])
			{
				float temp;
				temp=burst[i];
				burst[i]=burst[i+1];
				burst[i+1]=temp;
			}
		}
	}
	burst1[0]=burst[0];
	for(i=0;i<n-1;i++)
	{
		burst1[i+1]=burst1[i]+burst[i+1];
	}
	for(i=0;i<n-1;i++)
	{
		AvgWaiting=AvgWaiting+burst1[i];
	}
	free(burst1);
	return AvgWaiting/n ;
}
float SJF_T(int n , float *burst)
{
	int i;
	float AvgTurn=0,*burst1=(float *)malloc(n*sizeof(float));
	burst1[0]=burst[0];
	for(i=0;i<n-1;i++)
	{
		burst1[i+1]=burst1[i]+burst[i+1];
	}
	for(i=0;i<n;i++)
	{
		AvgTurn=AvgTurn+burst1[i];
	}
	free(burst1);
	return AvgTurn/n ;
}
float FCFS_W(int n , float *burst)
{
	int i;
	float AvgWaiting=0,*burst1=(float *)malloc(n*sizeof(float));
	burst1[0]=burst[0];
	for(i=0;i<n-1;i++)
	{
		burst1[i+1]=burst1[i]+burst[i+1];
	}
	for(i=0;i<n-1;i++)
	{
		AvgWaiting=AvgWaiting+burst1[i];
	}
	free(burst1);
	return AvgWaiting/n ;
}
float FCFS_T(int n , float *burst)
{
	int i;
	float AvgTurn=0,*burst1=(float *)malloc(n*sizeof(float));
	burst1[0]=burst[0];
	for(i=0;i<n-1;i++)
	{
		burst1[i+1]=burst1[i]+burst[i+1];
	}
	for(i=0;i<n;i++)
	{
		AvgTurn=AvgTurn+burst1[i];
	}
	free(burst1);
	return AvgTurn/n ;
}
int main()
{
	int process,i;
	printf("Enter no of process :");
	scanf("%d",&process);
	float *burst=(float *)malloc(process*sizeof(float));
	for(i=0;i<process;i++)
	{
		printf("Enter burst time of process %d :",i+1);
		scanf("%f",&burst[i]);
	}
	system("CLS");
	printf("Process\t  |   Burst time\n");
	printf("----------|-------------\n");
	for(i=0;i<process;i++)
	{
		printf("P%d\t  |   %f\n",i+1,burst[i]);
	}
	printf("------------------------\n");
	printf("Avg Waiting Time FCFS: %f\n",FCFS_W(process,burst));
	printf("a");
	printf("Avg TurnAround Time FCFS: %f\n\n",FCFS_T(process,burst));
	printf("Avg Waiting Time SJF: %f\n",SJF_W(process,burst));
	printf("Avg TurnAround Time SJF: %f\n",SJF_T(process,burst));
	free(burst);
	return 0;
}
