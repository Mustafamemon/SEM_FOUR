#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid=fork(); 
	if(pid==0){
		pid_t pid1=fork();
		if(pid1==0){
			pid_t pid2=fork();
			if(pid2==0){
				execl("/bin/ls","ls",NULL);
				perror("execl");			
			}
			else if(pid2>0){
				wait(NULL);
				printf("P3 Ends\n");	
			} 
		}
		else if(pid1>0){
			wait(NULL);
			printf("P2 Ends\n");		
		}	
	}
	else if(pid>0){
		wait(NULL);
		printf("P1 Ends\n");		
	}
}
