#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
        printf("I am Process 10 and my PID is %d\n",getpid());
        pid_t pid=fork();
        if(pid > 0)
        {
            pid_t pid1=fork();
            if(pid1 > 0)
            {
                wait(NULL);
            }
            else if( pid1 == 0)
            {
                printf("I am process 18 my PID is %d\n",getpid());
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
						printf("I am process 15 my PID is %ds\n",getpid());
					}
            		wait(NULL);
				}
				else if(pid3 == 0)
				{
					printf("I am process 21 my PID is %d\n",getpid());
				}
			}
            wait(NULL);
        }
        else if( pid == 0)
        {
            printf("I am process 6 my PID is %d\n",getpid());
            pid_t pid5=fork();
            if(pid5 > 0)
            {
            	pid_t pid6=fork();
            	if(pid6 > 0)
            	{
            		wait(NULL);
				}
				else if(pid6 == 0)
				{
					printf("I am process 4 my PID is %d\n",getpid());
				}
                wait(NULL);
            }
            else if(pid5 == 0)
            {
                printf("I am Process 8 my PID is %d\n",getpid());
            }
        }
        return 0;
}
