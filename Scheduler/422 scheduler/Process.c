/*
 * Process.c
 *
 *  Created on: Jun 2, 2013
 *      Author: TyPow
 */


#include "Process.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

/*
 * Constructs a Process
 */
ProcessPtr processConstructor(int proc_type){
	ProcessPtr proc = (ProcessPtr) malloc(sizeof(ProcessStr));
	proc->proc_type = proc_type;
	proc->no_steps = 2000; //Can be changed for however long you want process to run
	proc->no_requests = 3;//Change for how many interrupts you want i/o to do
	proc->requests[proc->no_requests];
	int i;
	srand(time(NULL));
	for(i = 0; i < proc->no_requests; i++) {//Adds the steps interrupts will happen
		proc->requests[i] = rand() % proc->no_steps;
	}
	return proc;
}
/** 
Test code for process
*/
int main(void){
ProcessPtr p = processConstructor(1);
printf("Process Type %d\n", p->proc_type);
printf("Number of steps %d\n", p->no_steps);
printf("Number of requests %d\n", p->no_steps);
int i=0;
for(i=0;i<MAX_SIZE;i++){
printf("Requests in it's array at index %d and is a %d request\n",i, p->requests[i]);
}
}
