//round robin with arrival time and preemptive
#include <stdio.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int status;
    int completion_time;
    int remaining_time;
    int turn_around_time;
    int waiting_time;
};

int main() {
    int n, i, j, k;
    float ttat = 0, twt = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
        p[i].process_id = i + 1;
        p[i].status = 0;
    }

    printf("Enter time quantum: ");
    int tq;
    scanf("%d", &tq);

    int completed_process = 0, ready_queue[100], rear = -1, front = 0, current_time = 0, arrived_process = 0;

    while (completed_process != n) {
        // Check for newly arrived processes and add to the ready queue
        if (arrived_process != n) {
            int a[n], num = 0;
            for (i = 0; i < n; i++) {
                if (p[i].status == 0 && p[i].arrival_time <= current_time) {
                    p[i].status = 1;
                    arrived_process++;
                    a[num++] = p[i].process_id;
                }
            }
            if (num != 0) {
                for (j = 0; j < num - 1; j++) {
                    for (k = 0; k < num - 1 - j; k++) {
                        if (p[a[k] - 1].arrival_time > p[a[k + 1] - 1].arrival_time) {
                            int t = a[k];
                            a[k] = a[k + 1];
                            a[k + 1] = t;
                        }
                    }
                }
                for (j = 0; j < num; j++) {
                    rear++;
                    ready_queue[rear] = a[j];
                }
            }
        }

        if (front <= rear) {
            int index = ready_queue[front++] - 1;
            if (p[index].remaining_time <= tq) {
                current_time += p[index].remaining_time;
                p[index].remaining_time = 0;
                p[index].completion_time = current_time;
                p[index].turn_around_time = p[index].completion_time - p[index].arrival_time;
                p[index].waiting_time = p[index].turn_around_time - p[index].burst_time;
                ttat += p[index].turn_around_time;
                twt += p[index].waiting_time;
                completed_process++;
            } else {
                p[index].remaining_time -= tq;
                current_time += tq;
                // Check for newly arrived processes again
                if (arrived_process != n) {
                    int a[n], num = 0;
                    for (i = 0; i < n; i++) {
                        if (p[i].status == 0 && p[i].arrival_time <= current_time) {
                            p[i].status = 1;
                            arrived_process++;
                            a[num++] = p[i].process_id;
                        }
                    }
                    if (num != 0) {
                        for (j = 0; j < num - 1; j++) {
                            for (k = 0; k < num - 1 - j; k++) {
                                if (p[a[k] - 1].arrival_time > p[a[k + 1] - 1].arrival_time) {
                                    int t = a[k];
                                    a[k] = a[k + 1];
                                    a[k + 1] = t;
                                }
                            }
                        }
                        for (j = 0; j < num; j++) {
                            rear++;
                            ready_queue[rear] = a[j];
                        }
                    }
                }
                ready_queue[++rear] = p[index].process_id;
            }
        } else {
            current_time++;
        }
    }

    printf("\nProcess    Arrival_time     Burst_time     Completion Time\tTurn_around_time\tWaiting_time\n");
    for (i = 0; i < n; i++) {
        printf("   P%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",
            p[i].process_id, p[i].arrival_time, p[i].burst_time,
            p[i].completion_time, p[i].turn_around_time, p[i].waiting_time);
    }
    printf("Average Turn around time = %.2f\n", ttat / n);
    printf("Average Waiting time = %.2f\n", twt / n);

    return 0;
}
