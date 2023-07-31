#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

typedef struct process
{
	int id,at,bt,ct,wt,tat;
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
	int n,Ttat=0,Twt=0,completed=0,time=0,minIndex,minBT;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the AT and BT of the processes\n");
	for(int i=0;i<n;i++)
	{
		p[i].id=i+1;
		scanf("%d%d",&p[i].at,&p[i].bt);
	}
	
	sort(n);
	
	p[0].wt=0;
	p[0].ct=p[0].bt+p[0].at;
	p[0].tat=p[0].ct-p[0].at;
	Ttat+=p[0].tat;
	if(p[0].at!=0) printf("Idle (%d) %d |",p[0].at,p[0].at);
	printf("P%d (%d) %d |",p[0].id,p[0].bt,p[0].ct);
	
	for(int i=1;i<n;i++) //All CTs
	{
		if(p[i].at>p[i-1].ct)
		{
			p[i].ct=p[i].at+p[i].bt;
			p[i].tat=p[i].ct-p[i].at;
			Ttat+=p[i].tat;
			p[i].wt=0;
			printf("Idle (%d) %d |",p[i].at-p[i-1].ct,p[i].at);
			printf("P%d (%d) %d |",p[i].id,p[i].bt,p[i].ct);
		}
		else
		{
			p[i].ct=p[i-1].ct+p[i].bt;
			p[i].tat=p[i].ct-p[i].at;
			Ttat+=p[i].tat;
			p[i].wt=p[i].tat-p[i].bt;
			Twt+=p[i].wt;
			printf("P%d (%d) %d |",p[i].id,p[i].bt,p[i].ct);
		}
	}
	
	
	
	printf("PID   AT   BT   CT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d   %d   %d   %d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
	}
	printf("Avg TAT %f\n",(float)Ttat/n);
	printf("Avg WT %f\n",(float)Twt/n);
}
