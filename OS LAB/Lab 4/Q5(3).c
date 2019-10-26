#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
        printf("I am Process 8 my PID is %d\n",getpid());
        pid_t pid = fork();
        if(pid > 0)
        {
            wait(NULL);
        }
        if( pid == 0)
        {
            printf("I am process 0 my PID is %d\n",getpid());
	    pid_t pid1 = fork();
	    if(pid1 > 0)
	    {
		pid_t pid2 = fork();
		if(pid2 > 0)
		{
		   wait(NULL);
		}
		if(pid2 == 0)
		{
		    printf("I am Process 2 my PID is %d\n",getpid());
		}
		wait(NULL);
	    }
	    if(pid1 == 0)
	    {
		printf("I am Process 7 my PID is %d\n",getpid());
	    }
        }
        return 0;
}
