#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	printf("I am Process 6 my PID is %d\n",getpid());
	pid_t pid = fork();
	if(pid > 0)
	{
	    wait(NULL);
	}
	if( pid == 0)
	{
	    printf("I am process 9 my PID is %d\n",getpid());
	}
	return 0;
}
