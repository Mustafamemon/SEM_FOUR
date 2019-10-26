#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
        printf("I am Process root my PID is %d\n",getpid());
        pid_t pid = fork();
        if(pid > 0)
        {
	    pid_t pid1 = fork();
	    if(pid1 > 0)
	    {
		wait(NULL);
	    }
	    if( pid1 == 0)
	    {
		 printf("I am process leaf my PID is %d\n",getpid());
	    }
            wait(NULL);
        }
        if( pid == 0)
        {
            printf("I am process innerNode my PID is %d\n",getpid());
	    pid_t pid2=fork();
	    if(pid2 > 0)
	    {
		pid_t pid3=fork();
		if(pid3 > 0)
                {
		    wait(NULL);
            	}
            	if( pid3 == 0)
            	{
                     printf("I am process leaf my PID is %d\n",getpid());
            	}
		wait(NULL);
	    }
	    if( pid2 == 0)
	    {
		 printf("I am process leaf my PID is %d\n",getpid());
	    }
        }
        return 0;
}
