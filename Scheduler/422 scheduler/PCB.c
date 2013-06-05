/*
 * PCB.c
 *
 *  Created on: May 26, 2013
 *      Author: TyPow
 */

#include "PCB.h"



/*
 * Constructs a PCB.
 */
PCBPtr pcbConstructor(int pid, ProcessPtr proc) {
	PCBPtr pcb = (PCBPtr) malloc(sizeof(PCBStr));
	pcb->pid = pid;
	pcb->proc = proc;
	pcb->state = 1;
	pcb->next_step = 0;
	pcb->waiting_on = 0;
	pcb->owns = 0;
	return pcb;
}

/**
int main(void){
ProcessPtr t1 = processConstructor(1);
PCBPtr p1 = pcbConstructor(1,t1);
printf("Number of steps: %d\n",p1->proc->no_steps);
printf("The processes type %d\n",p1->proc->proc_type);
printf("The current state%d\n", p1->state);
printf("It's next step: %d\n", p1->next_step);
printf("Mutex it is waiting on: %d\n", p1->waiting_on);
printf("Mutex it currently owns: %d\n", p1->owns);
}

*/
