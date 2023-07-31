#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

typedef struct process
{
	int id,at,bt,ct,wt,tat,visited,BT;
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
	int n,Ttat=0,Twt=0,completed=0,time=0,curI,quantum;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the AT and BT of the processes\n");
	for(int i=0;i<n;i++)
	{
		p[i].id=i+1;
		scanf("%d%d",&p[i].at,&p[i].bt);
		p[i].BT=p[i].bt;
		p[i].visited=0;
	}
	printf("Enter time quantum: ");
	scanf("%d",&quantum);
	
	sort(n);
	
	int Q[100]={0},front=0,rear=-1;
	Q[++rear]=0;
	p[0].visited=1;
	int count=1;
	
	while(completed!=n)
	{
		curI=Q[front++];
		count--;
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
			completed++;
			p[curI].ct=time;
			p[curI].tat=p[curI].ct-p[curI].at;
			p[curI].wt=p[curI].tat-p[curI].BT;
			Ttat+=p[curI].tat;
			Twt+=p[curI].wt;
		}
		for(int i=1;i<n;i++)
		{
			if(p[i].at<=time && !p[i].visited)
			{
			Q[++rear]=i;
			p[i].visited=1;
			count++;
			}
		}
		if(p[curI].bt>0)
		{
			Q[++rear]=curI;
			count++;
		}
		while(front>rear && completed<n) //or count==0
		{
			time++;
			printf("|idle (1) %d",time);
			for(int i=1;i<n;i++)
			{
				if(p[i].at<=time && !p[i].visited)
				{
					Q[++rear]=i;
					p[i].visited=1;
					count++;
				}
			}
		}
	}
	printf("\n");
	printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].BT,p[i].ct,p[i].wt,p[i].tat);
	}
	printf("Avg TAT %f\n",(float)Ttat/n);
	printf("Avg WT %f\n",(float)Twt/n);
}
