 #include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int sum=0,prod=1;

void* mul(void* parm)
{
	int n=atoi(parm);
	printf("Inside mul thread\n");
	for(int i=2;i<=n;i++)
	{
		prod*=i;
	}
	printf("Mul thread completed\n");
}

void* add(void* parm)
{
	int n=atoi(parm);
	printf("Inside add thread\n");
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	printf("Add thread completed\n");
}

void main(int argc,int* argv[])
{
	if(argc<2)
	{
		printf("Enter command line\n"); exit(0);
	}
	pthread_t t1,t2;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&t1,&attr,(void*)mul,argv[1]);
	pthread_create(&t2,&attr,(void*)add,argv[1]);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Inside main thread\n");
	printf("Sum=%d\tProduct=%d\n",sum,prod);
}
