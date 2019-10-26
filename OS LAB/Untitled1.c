#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h> 
#define MAX 1000

int max_num(int arr[],int n)
{
	int temp=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(temp<arr[i])
		temp=arr[i];
	}
	return temp;
}

int min_num(int arr[],int n)
{
	int temp=max_num(arr,n);
	int i;
	for(i=0;i<n;i++)
	{
		if(temp>arr[i])
		temp=arr[i];
	}
	if(temp>0)
	temp=0;
	return temp;
}
void count_sort(int arr[],int arr2[],int output[],int n)
{
	int max=max_num(arr2,n);
	int min=min_num(arr2,n);
	int arr1[max-min+1];	
	int i,j;
	for(i=0;i<max-min+1;i++)
		arr1[i]=0;
	#pragma omp parallel sections num_threads(2)
	{
		#pragma omp section
		{
			for(i=min;i<=max;i++)
			{
				for(j=0;j<n;j++)
					if(arr2[j]==i)
						arr1[i-min]++;
			}
		}
		//CF:Cum.fre
		#pragma omp section
		{
			for(i=1;i<=max-min;i++)
			{
				arr1[i]=arr1[i-1]+arr1[i];
			}
			for(i=0;i<n;i++)
			{
				arr1[arr2[i]-min]--;	
				output[arr1[arr2[i]-min]]=arr[i];
			}
		}
	}
}

int * radix_sort(int arr[],int n)
{
	int max=max_num(arr,n);
	int i=10;
	while(max>0)
	{
		max/=i;
		i*=10;
	}
	int arr1[n];
	int *output;
	output=(int *)malloc(n*sizeof(int));
	int j,k;
	for(j=10;j<=i;j*=10)
	{
		for(k=0;k<n;k++)
		{
			arr1[k]=arr[k]%j;
		}
		count_sort(arr,arr1,output,n);
	}
	return output;
}

void print(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int A[MAX],i;
    srand(time(NULL));
    for(i=0;i<MAX;i++){
     A[i] = rand() % MAX;
    }
    clock_t t1,t2;
    t1 = clock();
    int *output=radix_sort(A,MAX);
    t2 = clock();
    double time = (double)(t2-t1)/CLOCKS_PER_SEC;
    printf("Sorted array: ");
    print(output, MAX);
    printf("\t\tTime Elapsed: %.5f\n",time);
    return 0;
}
