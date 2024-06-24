//FCFS without arrival time
#include<stdio.h>
void main()
{
	printf("Enter total number of processes:");
	int n,i;
	scanf("%d",&n);
	int bt[n],ct[n],wt[n];
	for(i=0 ; i<n ; i++)		//Taking burst-times as input
	{
		printf("Enter Process-%d Burst Time:",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0,ct[0]=bt[0];
	float ttat=ct[0],twt=0;
	for(i=1 ; i<n ; i++)	//Calculate Completion,TurnAround  and waiting times
	{
		ct[i]=ct[i-1]+bt[i];
		wt[i]=ct[i-1];
		twt=twt+wt[i];
		ttat=ttat+ct[i];	
	}
	printf("Process   Burst Time  Completion Time   TurnAround Time   Wating time\n");
	for(i=0 ; i<n ; i++)
	{
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],ct[i],ct[i],wt[i]);
	}
	printf("Average Turnaround time=%.2f\n",ttat/n);
	printf("Average waiting time=%.2f",twt/n);
}
