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
		printf("[CHILD] Sleeping for 10 seconds...\n");
		sleep(10);
		printf("[CHILD] My parent has ended, so I am an orphan process adopted by init\n");
	}
	else
	{
		mypid=getpid();
		ppid=getppid();
		printf("[PARENT] My pid is %d\n",mypid);
		printf("[PARENT] My parents pid is %d\n",ppid);
		printf("[PARENT] Exiting...\n");
		exit(0);
	}
}
