/*
 * PCB.h
 *
 *  Created on: May 22, 2013
 *      Author: TyPow
 */
#include <stdio.h>
#include <stdlib.h>
#include "Process.h"


typedef struct {
	int	pid;
	int next_step;		// this is the step count that the CPU had gotten to when this process was
						// prempted (like a PC register value)
	int state;			// e.g. 0=running, 1=ready, 2=interrupted, 3=blocked
	ProcessPtr proc;    // pointer to the actual process
	int waiting_on;		// which queue is it in if it is waiting on something (blocked)
	int owns;			// which mutex lock does it own
} PCBStr;


typedef PCBStr *PCBPtr;

PCBPtr pcbConstructor(int, ProcessPtr);
