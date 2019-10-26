#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(void) {
	int pipefd[2];
	int pipefd1[2];
	int pid;
	char buffer[10];
	pipe(pipefd);
	pipe(pipefd1);
	pid = fork();

	if(pid > 0) {
		fflush(stdin);
		write(pipefd[1],"Mr.Linux",9);
	}
	else if(pid == 0) {
		sleep(5);
		fflush(stdin);
		printf("Child Process\n");
		read(pipefd[0], buffer, sizeof(buffer));
		write(1,buffer, sizeof(buffer));
		write(pipefd1[1],"Mr.Ubuntu",10);
		printf("\n");	
	}
	else {
		printf("Error in creating child process\n");	
	}
	if(pid > 0) {
		wait(NULL);
		printf("Parent Process\n");
		read(pipefd1[0], buffer, sizeof(buffer));
		write(1,buffer, sizeof(buffer));
		printf("\n");
	}
	return 0;
}
	
