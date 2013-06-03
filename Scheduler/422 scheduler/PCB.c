/*
 * PCB.c
 *
 *  Created on: May 26, 2013
 *      Author: TyPow
 */

#include "Process.h"
#include "PCB.h"
#include <stdio.h>
#include <stdlib.h>


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
