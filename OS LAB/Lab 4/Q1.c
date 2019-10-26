#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int pid=fork();
	if(pid>0){
		wait(NULL);
		for(int i=1;i<=10;i++)	
		{
			if(i%2==0)
			printf("\n%d ",i);
		}	
		printf("\nParent Ends");	
	}
	else if(pid==0){	
		printf("\n Parent PID is %d ",getpid());
		for(int i=1;i<=10;i++)	
		{
			if(i%2!=0)
			printf("\n%d ",i);
		}	
		printf("\nParent Ends");
	}
	else if(pid<0){
		printf("\nUnsucessful Child Process Creation");
	}
	return 0;
}
