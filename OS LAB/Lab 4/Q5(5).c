#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
        printf("I am Process A my PID is %d\n",getpid());
        pid_t pid=fork();
        if(pid > 0)
        {
	    	pid_t pid1=fork();
            if(pid1 > 0)
            {
				pid_t pid2 = fork();
            	if(pid2 > 0)
            	{
		    		wait(NULL);
            	}
            	else if( pid2 == 0)
            	{
               	    printf("I am Process D my PID is %d\n",getpid());
		    		pid_t pid3=fork();
		    		if(pid3 > 0)
		    		{
						pid_t pid4=fork();
						if(pid4 > 0)
						{
						    wait(NULL);
						}
						else if(pid4 == 0)
						{
						    printf("I am Process H my PID is %d\n",getpid());
						}
						wait(NULL);
			    	}
				    else if(pid3 == 0)
				    {
						printf("I am Process G my PID is %d\n",getpid());
				    }
            	}
                wait(NULL);
            }
            else if( pid1 == 0)
            {
                printf("I am process C my PID is %d\n",getpid());
            }
       	    wait(NULL);
        }
        else if( pid == 0)
        {
            printf("I am process B my PID is %d\n",getpid());
	    	pid_t pid5=fork();
		    if(pid5 > 0)
		    {
				pid_t pid6=fork();
				if(pid6 > 0)
				{
					wait(NULL);
				}
				else if( pid6 == 0)
				{
					printf("I am Process F my PID is %d\n",getpid());
				}
				wait(NULL);
	    	}
		    else if(pid5 == 0)
		    {
				printf("I am Process E my PID is %d\n",getpid());
		    }
        }
        return 0;
}
