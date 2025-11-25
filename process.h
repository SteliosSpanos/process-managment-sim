#pragma once
#define TRUE 1
#define FALSE 0

typedef struct process {
	unsigned int pid;
} process;

int init_process(process *p, unsigned int pid);


