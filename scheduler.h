#pragma once
#include "process.h"
#include "ready-queue.h"

typedef struct scheduler_stats {
	float avg_waiting_time;
	float avg_turnaround_time;
	float avg_response_time;
	float cpu_util;
	unsigned int total_time;
} scheduler_stats;

void fcfs(process* processes, int num_processeses, scheduler_stats* stats);

void calculate_metrics(process* processes, int num_processes, scheduler_stats* stats, unsigned int total_time);

void print_stats(scheduler_stats* stats);

void print_process_details(process* processes, int num_processes);
