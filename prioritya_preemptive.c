//priority preemptive with arrival time
#include <stdio.h>

struct Process 
{
    int process_id;
    int priority;
    int arrival_time;
    int burst_time;
    int status;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    int remaining_time;
};

int main() 
{
    int n, i, min_arrival_time=1000;
    float ttat=0,twt=0;
   	printf("Enter the number of processes: ");
   	scanf("%d", &n);

   	struct Process processes[n];

    
   	// Input arrival time and burst time for each process
   	for (i = 0; i < n; i++) 
	{
		printf("Enter priority for process P%d: ", i + 1);
       	scanf("%d", &processes[i].priority);
       	printf("Enter arrival time for process P%d: ", i + 1);
       	scanf("%d", &processes[i].arrival_time);
       	printf("Enter burst time for process P%d: ", i + 1);
       	scanf("%d", &processes[i].burst_time);
       	processes[i].remaining_time=processes[i].burst_time;
       	processes[i].process_id = i + 1;
       	processes[i].status = 0;
       	
       	if (processes[i].arrival_time < min_arrival_time)
           	min_arrival_time = processes[i].arrival_time;
   	}

   	int current_time = min_arrival_time;
   	int completed_process=0;

    // priority scheduling
	while (completed_process !=n) 
 	{
        // Finding processes that have arrived and not completed yet
       	int eligible_processes[n];
       	int num_eligible = 0;
       	for (i = 0; i < n; i++) 
		{
           	if (processes[i].arrival_time <= current_time && processes[i].status == 0) 
			{
               	eligible_processes[num_eligible] = i;
               	num_eligible++;
           	}
       	}
		if(num_eligible != 0)
		{
	       	// Finding the process with the highest priority
    	   	int shortest_index = eligible_processes[0];
    	   	if(num_eligible != 1)
			{
       			for (i = 1; i < num_eligible; i++) 		
				{
            		int index = eligible_processes[i];
            		if (processes[index].priority < processes[shortest_index].priority)
               			shortest_index = index;
        		}
        	}
        	if( processes[shortest_index].remaining_time==1)
        	{
        		processes[shortest_index].remaining_time=0;
        		processes[shortest_index].status=1;
        		processes[shortest_index].completion_time=current_time+1;
        		processes[shortest_index].turn_around_time = processes[shortest_index].completion_time - processes[shortest_index].arrival_time;
        		processes[shortest_index].waiting_time = processes[shortest_index].turn_around_time - processes[shortest_index].burst_time;
        	    ttat +=  processes[shortest_index].turn_around_time ;
        		twt += processes[shortest_index].waiting_time;
        		completed_process++;
				current_time++;
			}
			else
			{
			
        		// Update the selected process data
       			processes[shortest_index].remaining_time--;

				// Update current time and iteration value
        		current_time++;
        	
        	}
    	}
    	else
    	{
    		current_time++;
		}
    }

    // Display data of each process
    printf("\nProcess     Priority   Arrival_time     Burst_time     Completion Time\tTurn_around_time\tWaiting_time\n");
    for (i = 0; i < n; i++) 
	{
       	printf("   P%d\t\t%d  \t  %d  \t  \t  %d  \t  \t  %d\t\t\t%d\t\t\t%d\n", processes[i].process_id,processes[i].priority, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turn_around_time,processes[i].waiting_time);
    }
    printf("Average Turn around time=%.2f\n",ttat/n);
    printf("Average Waiting time=%.2f\n",twt/n);

    	return 0;
}
