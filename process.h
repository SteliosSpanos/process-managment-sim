#pragma once
#define TRUE 1
#define FALSE 0

typedef struct process {
	unsigned int pid;
	int memory_given;
} process;

int init_process(process *p, unsigned int pid) {
	p->pid = pid;
	p->memory_given = FALSE;
}


