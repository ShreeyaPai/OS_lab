#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

typedef struct process
{
	int id,at,bt,pri,ct,wt,tat;
}pro;

pro p[10];

void main()
{
	int n,tempBT[10],Ttat=0,Twt=0,completed=0,time=0,minIndex,minP;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the AT, BT and Prio of the processes\n");
	for(int i=0;i<n;i++)
	{
		p[i].id=i+1;
		scanf("%d%d%d",&p[i].at,&p[i].bt,&p[i].pri);
		tempBT[i]=p[i].bt;
	}
	while(completed!=n)
	{
		minP=INT_MAX;
		minIndex=-1;
		for(int i=0;i<n;i++)
		{
			if(p[i].at<=time && p[i].bt>0)
			{
				if(p[i].pri<minP || p[i].pri==minP && p[i].at<p[minIndex].at)
				{
					minP=p[i].pri;
					minIndex=i;
				}
			}
		}
		time++;
		if(minIndex!=-1)
		{
			p[minIndex].bt--;
			printf(" |P%d (1) %d | ",p[minIndex].id,time);
			
			if(p[minIndex].bt==0)
			{
				completed++;
				p[minIndex].ct=time;
				p[minIndex].tat=p[minIndex].ct-p[minIndex].at;
				p[minIndex].wt=p[minIndex].tat-tempBT[minIndex];
				Ttat+=p[minIndex].tat;
				Twt+=p[minIndex].wt;
			}
		}
	}
	printf("PID   AT   BT   CT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d   %d   %d   %d\t%d\t%d\n",p[i].id,p[i].at,tempBT[i],p[i].ct,p[i].wt,p[i].tat);
	}
	printf("Avg TAT %f\n",(float)Ttat/n);
	printf("Avg WT %f\n",(float)Twt/n);
}
