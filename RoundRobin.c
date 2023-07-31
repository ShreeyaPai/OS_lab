#include<stdlib.h>
#include<stdio.h>


typedef struct process
{
	int id,at,bt,ct,wt,tat,flag;
}pro;

pro p[10];

void swap(pro* a,pro *b)
{
	pro temp=*a;
	*a=*b;
	*b=temp;
}

void sort(int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(p[j].at>p[j+1].at)
				swap(&p[j],&p[j+1]);
		}
	}
}

void main()
{
	int n,tempBT[10],Ttat=0,Twt=0,completed=0,time=0,curI,quantum;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the AT and BT of the processes\n");
	for(int i=0;i<n;i++)
	{
		p[i].id=i+1;
		scanf("%d%d",&p[i].at,&p[i].bt);
		tempBT[i]=p[i].bt;
		p[i].flag=0;
	}
	printf("Enter time quantum: ");
	scanf("%d",&quantum);
	
	sort(n);
	
	int Q[10],front=0,rear=0;
	Q[rear]=0;
	p[0].flag=1;
	
	while(completed!=n)
	{
		curI=Q[front];
		front=(front+1)%n;
		if(p[curI].bt>quantum)
		{
			time+=quantum;
			printf(" | P%d (%d) %d | ",p[curI].id,quantum,time);
			p[curI].bt-=quantum;
		}
		else
		{
			time+=p[curI].bt;
			printf(" | P%d (%d) %d | ",p[curI].id,p[curI].bt,time);
			p[curI].bt=0;
		}
		for(int i=0;i<n && p[i].at<=time;i++)
		{
			if(i==curI || p[i].bt==0 || p[i].flag) continue;
			rear=(rear+1)%n;
			Q[rear]=i;
			p[i].flag=1;
		}
		if(p[curI].bt!=0)
		{
			rear=(rear+1)%n;
			Q[rear]=curI;
		}
		else
		{
			completed++;
			p[curI].ct=time;
			p[curI].tat=p[curI].ct-p[curI].at;
			p[curI].wt=p[curI].tat-tempBT[curI];
			Ttat+=p[curI].tat;
			Twt+=p[curI].wt;
		}
	}
	printf("\n");
	printf("PID   AT   BT   CT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d   %d   %d   %d\t%d\t%d\n",p[i].id,p[i].at,tempBT[i],p[i].ct,p[i].wt,p[i].tat);
	}
	printf("Avg TAT %f\n",(float)Ttat/n);
	printf("Avg WT %f\n",(float)Twt/n);
}
