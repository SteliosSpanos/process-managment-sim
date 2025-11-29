#pragma once
#define TRUE 1
#define FALSE 0

typedef enum {
	NEW,
	READY,
	RUNNING,
	WAITING,
	TERMINATED
} process_state;


typedef struct process {
	unsigned int pid;
	process_state state;
	unsigned int arrival_time;
	unsigned int remaining_time;
	unsigned int burst_time;
	unsigned int priority;
	unsigned int waiting_time;
	unsigned int turnaround_time;
	unsigned int response_time;
	int first_run;
} process;

void init_process(process *p, unsigned int pid, unsigned int arrival_time, unsigned int burst_time, unsigned int priority);


