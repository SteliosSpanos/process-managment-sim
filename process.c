#include "process.h"

void init_process(process *p, unsigned int pid, unsigned int arrival_time, unsigned int burst_time, unsigned int priority) {
	p->state = NEW;
	p->pid = pid;
	p->arrival_time = arrival_time;
	p->burst_time = burst_time;
	p->priority = priority;
}

