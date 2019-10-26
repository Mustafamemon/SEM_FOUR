#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	printf("I am Process 1 my PID is %d\n",getpid());
	pid_t pid = fork();

	if( pid > 0)
	{
	    pid_t pid1 = fork();
	    if(pid1 > 0)
	    {
		wait(NULL);
	    }
	    if( pid1 == 0)
	    {
	    	printf("I am Process 5 my PID is %d\n",getpid());
	    }
	    wait(NULL);
	}
	else if( pid == 0)
	{
	    printf("I am Process 3 my PID is %d\n",getpid());
	    pid_t pid2 = fork();
	    if(pid2 > 0)
	    {
		wait(NULL);
	    }
	    if (pid2 == 0)
	    {
		 printf("I am Process 4 my PID is %d\n",getpid());
	    }
	}
	return 0;
}
