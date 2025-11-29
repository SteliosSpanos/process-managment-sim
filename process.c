#include "process.h"

void init_process(process *p, unsigned int pid, unsigned int arrival_time, unsigned int burst_time, unsigned int priority) {
	p->state = NEW;
	p->pid = pid;
	p->arrival_time = arrival_time;
	p->burst_time = burst_time;
	p->priority = priority;
  p->remaining_time = burst_time;
  p->waiting_time = 0;
  p->turnaround_time = 0;
  p->response_time = 0;
  p->first_run = 0;


