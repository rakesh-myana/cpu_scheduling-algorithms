#include<stdio.h>
void main()
{
	printf("Enter total number of process:");
	int n,i,j;
	scanf("%d",&n);
	int p[n],at[n],bt[n],ct[n],tat[n],wt[n];
	float ttat=0,twt=0;
	for(i=0 ; i<n ; i++)
	{
		printf("Enter Process-%d Arrival Time:",i+1);
		scanf("%d",&at[i]);
		printf("Enter Process-%d Burst Time  :",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0; i<(n-1); i++)
    {
        for( j=0; j<(n-1-i); j++)
        {
            if(at[j]>at[j+1])
            {
                int t=at[j];
                at[j]=at[j+1];
                at[j+1]=t;
                
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;
                
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    wt[0]=0,ct[0]=bt[0]+at[0];
	for(i=1 ; i<n ; i++)
	{
		ct[i]=ct[i-1]+bt[i];	
	}
	for(i=0 ; i<n ; i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		twt=twt+wt[i];
		ttat=ttat+tat[i];	
	}
	printf("Process  Arrival_Time  Burst_Time  Compilation_Time   TurnAround_Time   Wating_time\n");
	for(i=0 ; i<n ; i++)
	{
		printf("  P%d\t\t%d\t   %d\t\t%d\t\t\t%d\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	printf("Average Turnaround time=%.2f\n",ttat/n);
	printf("Average waiting time=%.2f",twt/n);
}
