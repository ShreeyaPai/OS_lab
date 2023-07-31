#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	pid_t mypid,ppid,childpid;
	childpid=fork();
	if(childpid<0)
	{
		printf("Fork failed\n"); exit(0);
	}
	if(childpid==0)
	{
		mypid=getpid();
		ppid=getppid();
		printf("[CHILD] My pid is %d\n",mypid);
		printf("[CHILD] My parents pid is %d\n",ppid);
		printf("[CHILD] Exiting...\n");
		exit(0);
	}
	else
	{
		mypid=getpid();
		ppid=getppid();
		printf("[PARENT] My pid is %d\n",mypid);
		printf("[PARENT] My parents pid is %d\n",ppid);
		printf("[PARENT] Sleeping for 10 seconds\n");
		sleep(10);
		printf("[PARENT] Child process %d has ended, but still has an entry in the process table, so it is a zombie process\n",childpid);
	}
}
