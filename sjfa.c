//SJF non_preemtive with arrival time
#include <stdio.h>
 
struct Process 
{
    int process_id;
    int arrival_time;
    int burst_time;
    int status;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main() 
{
    int n, i;
    float ttat=0,twt=0;
   	printf("Enter the number of processes: ");
   	scanf("%d", &n);

   	struct Process p[n];
    
   	// Input arrival time and burst time for each process
   	for (i = 0; i < n; i++) 
	{
       	printf("Enter arrival time for process P%d: ", i + 1);
       	scanf("%d", &p[i].arrival_time);
       	printf("Enter burst time for process P%d: ", i + 1);
       	scanf("%d", &p[i].burst_time);
       	p[i].process_id = i + 1;
       	p[i].status = 0;
    }

   	int current_time = 0;
   	int completed_process=0;

    // SJF scheduling
	while (completed_process !=n) 
 	{
        // Finding processes that have arrived and not completed yet
       	int eligible_processes[n];
       	int num_eligible = 0;
       	for (i = 0; i < n; i++) 
		{
           	if (p[i].arrival_time <= current_time && p[i].status == 0) 
			{
               	eligible_processes[num_eligible] = i;
               	num_eligible++;
           	}
       	}
		if(num_eligible != 0)
		{
	       	// Finding the process with the shortest burst time
    	   	int shortest_index = eligible_processes[0];
       		for (i = 1; i < num_eligible; i++) 		
			{
            	int index = eligible_processes[i];
            	if (p[index].burst_time < p[shortest_index].burst_time)
               		shortest_index = index;
        	}

        	// Update the selected process data
       		p[shortest_index].completion_time = current_time + p[shortest_index].burst_time;
        	p[shortest_index].status = 1;
        	p[shortest_index].turn_around_time = p[shortest_index].completion_time - p[shortest_index].arrival_time;
        	p[shortest_index].waiting_time = p[shortest_index].turn_around_time - p[shortest_index].burst_time;
        
        	ttat +=  p[shortest_index].turn_around_time ;
        	twt += p[shortest_index].waiting_time;
        	
			// Update current time and iteration value
        	current_time = p[shortest_index].completion_time;
        	completed_process++;
    	}
    	else
    	{
    		current_time++;
		}
    }

    // Display data of each process
    printf("\nProcess    Arrival_time     Burst_time     Completion Time\tTurn_around_time\tWaiting_time\n");
    for (i = 0; i < n; i++) 
	{
       	printf("   P%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time,p[i].waiting_time);
    }
    printf("Average Turn around time=%.2f\n",ttat/n);
    printf("Average Waiting time=%.2f\n",twt/n);

    	return 0;
}

