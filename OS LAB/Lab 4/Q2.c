#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int cnt=0;	
	pid_t pid=fork();	
	for(int i=0;i<=5;i++)
	{ 
		printf("%d ",cnt);
		cnt++;
	}
	if(pid>0){
		wait(NULL);
		printf("\nGrand Parent PID is %d ",getppid());
		printf("\nProcess PID is %d ",getpid());			
		printf("\nParent Ends\n");
		
	}
	else if(pid==0){
		sleep(3);
		printf("\nChilds Ends\n");		
		execl("/usr/bin/gedit","gedit",(char*)0);
		perror("excel");				
	} 
	else if(pid<0){
		printf("\nUnsucessful Child Process Creation");
	}
	return 0;
}
