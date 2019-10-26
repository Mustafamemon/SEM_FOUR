#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int main()
{
	time_t t ;
	pid_t pid=fork();
	if(pid>0)
	{
		
		//A
		//printf("A pid %d  %d\n",getpid(),getppid());
		wait(NULL);	
		time(&t);	
				
		pid_t pid1=fork();
		if(pid1>0)
		{
			wait(NULL);
			pid_t pid2=fork();
			if(pid2>0)
			{
				wait(NULL);
				printf("A : %s\n",ctime(&t));
			}
			else if(pid2==0)
			{
				//D
				time(&t);
				printf("D : %s\n",ctime(&t));
			        char c[100]={0};
				sprintf(c,"./Q4d.sh");
				system(c);
				//printf("D pid %d  %d\n",getpid(),getppid());
			}
		}
		else if(pid1==0)
		{	
			pid_t pid3=fork();
			if(pid3>0)
			{
				//C
				sleep(5);				
				wait(NULL);					
				printf("F : GrandParent PID %d\n\n",getppid());
				time(&t);	
				printf("C : %s\n",ctime(&t));
			}
			else if(pid3==0)
			{
				//F
				time(&t);
				printf("F : %s",ctime(&t));
				
			}
		}		
	}
	else if(pid==0)
	{
		
		pid_t pid4=fork();
		if(pid4>0)
		{
			wait(NULL);
			char c1[100]={0};
			//printf("B pid %d  %d\n",getpid(),getppid());
			time(&t);		
			printf("B : %s\n",ctime(&t));		
			sprintf(c1,"./Q4b.sh %d %d",20 , 5);
			system(c1);
		}
		else if(pid4==0)
		{
			//e
			//  printf("E pid %d  %d\n",getpid(),getppid());
			time(&t);
			printf("E : %s\n",ctime(&t));
	execlp("/sbin/ifconfig","ifconfig -a | grep ether",(char *)0);
			perror("execlp");
			printf("\n");
		}
	}
	
	return 0;
}
