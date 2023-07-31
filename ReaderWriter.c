#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t wrt;
pthread_mutex_t mutex;
int val=2,readcount=0;

void* write(void* wno)
{
	sem_wait(&wrt);
	val*=2;
	printf("Writer %d changed value to %d\n",*((int*)wno),val);
	sem_post(&wrt);
}

void* read(void* rno)
{
	pthread_mutex_lock(&mutex);
	readcount++;
	if(readcount==1) sem_wait(&wrt);
	pthread_mutex_unlock(&mutex);
	printf("Reader %d read value as %d\n",*((int*)rno),val);
	pthread_mutex_lock(&mutex);
	readcount--;
	if(readcount==0) sem_post(&wrt);
	pthread_mutex_unlock(&mutex);	
}

void main()
{
	pthread_t reader[10],writer[10];
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	sem_init(&wrt,0,1);
	pthread_mutex_init(&mutex,NULL);
	for(int i=0;i<10;i++)
	{
		pthread_create(&writer[i],NULL,(void*)read,(void*)&a[i]);
		pthread_create(&reader[i],NULL,(void*)write,(void*)&a[i]);
	}
	for(int i=0;i<10;i++)
	{
		pthread_join(writer[i],NULL);
		pthread_join(reader[i],NULL);
	}
	pthread_mutex_destroy(&mutex);
	sem_destroy(&wrt);
}
