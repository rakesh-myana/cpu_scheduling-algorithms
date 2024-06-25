//SJF without arrival time
#include<stdio.h>
void main()
{
	printf("Enter total number of processes:");
	int n,i,j;
	scanf("%d",&n);
	int bt[n],ct[n],wt[n],p[n];
	for(i=0 ; i<n ; i++)
	{
		printf("Enter Process-%d Burst Time:",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0; i<(n-1); i++)
    {				//sorting based on burst time
        for( j=0; j<(n-1-i); j++)
        {
            if(bt[j]>bt[j+1])
            {
                int t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;
                
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    ct[0]=bt[0],wt[0]=0;
    float ttat=ct[0],twt=0;
    for(i=1 ; i<n ; i++)
    {
    	ct[i]=bt[i]+ct[i-1];
    	wt[i]=ct[i-1];
    	ttat=ttat+ct[i];
		twt=twt+wt[i];
			
	}
	printf("Process   Burst Time  Completion Time   TurnAround Time   Wating time\n");
	for(i=0 ; i<n ; i++)
	{
		printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],ct[i],ct[i],wt[i]);
	}
	printf("Average Turnaround time=%.2f\n",ttat/n);
	printf("Average waiting time=%.2f",twt/n);
}
    	
	
