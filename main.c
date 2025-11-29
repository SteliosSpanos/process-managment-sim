#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "process.h"
#include "ready-queue.h"
#include "scheduler.h"


int main() {
	process processes[3];

  	init_process(&processes[0], 1, 0, 8, 2);
  	init_process(&processes[1], 2, 1, 4, 1);
  	init_process(&processes[2], 3, 2, 9, 3);

  	// Run FCFS scheduler
  	scheduler_stats stats;
  	fcfs(processes, 3, &stats);


  	return 0;
		
}
	
