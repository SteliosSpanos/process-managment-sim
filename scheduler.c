#include "scheduler.h"
#include <stdio.h>

void fcfs(process* processes, int num_processes, scheduler_stats* stats) {
	queue ready_q;
	init_queue(&ready_q);

	unsigned int current_time = 0;
	int completed = 0;
	int next_process = 0;

	printf("\n=== FCFS Scheduling Simulation ===\n");
  	printf("Time | Event\n");
  	printf("-----|------\n");

	while (completed < num_processes) {
		while (next_process < num_processes && processes[next_process].arrival_time <= current_time) {
			processes[next_process].state = READY;
			enqueue(&ready_q, processes[next_process]);
			printf("%4u | P%u arrives\n", current_time, processes[next_process].pid);
			next_process++;
		}

		process current_p;
		if (dequeue(&ready_q, &current_p) == 0) {
			int idx = -1;
			for (int i = 0; i < num_processes; i++) {
				if (processes[i].pid == current_p.pid) {
					idx = i;
					break;
				}
			}
			
			if (idx != -1) {
				if (processes[idx].first_run == 0) {
					processes[idx].response_time = current_time - processes[idx].arrival_time;
					processes[idx].first_run = 1;
				}
				
				processes[idx].state = RUNNING;
				printf("%4u | P%u starts (burst=%u)\n", current_time, processes[idx].pid, processes[idx].burst_time);

				current_time += processes[idx].burst_time;

				processes[idx].state = TERMINATED;
				processes[idx].remaining_time = 0;
				processes[idx].turnaround_time = current_time - processes[idx].arrival_time;
				processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
				printf("%4u | P%u completes\n", current_time, processes[idx].pid);

				completed++;
			}
		}
		else {
			current_time++;
		}
	}

	printf("\n");
	stats->total_time = current_time;
	free_queue(&ready_q);
}
				
		

	
