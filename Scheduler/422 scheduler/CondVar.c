/*
 * CondVar.c
 *
 *  Created on: Jun 2, 2013
 *      Author: TyPow
 */


#include "Process.h"
#include "PCB.h"
#include "Queue.h"
#include "CondVar.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs a Condition Variable that has an id, its waiting queue, and the current
 * owner of the variable.
 */
CondVarPtr condvarConstructor(int var_ID, PCBQueuePtr condvarq) {
	CondVarPtr condvar = (CondVarPtr) malloc(sizeof(CondVar));
	condvar->condID = var_ID;
	condvar->condQueue = condvarq;
	return condvar;
}

/*
 * Changes the owner of the variable to the next PCBPtr waiting at the head of the queue.
 */
void switchcondvarOwner(CondVarPtr condvar) {
	condvar->ownerID = dequeue(condvar->condQueue);
	condvar->ownerID->state = 1;
}

/*
 * Adds the PCBPtr to the waiting queue for this variable.
 */
void condvarWaiting(CondVarPtr condvar, PCBPtr pcb) {
	pcb->waiting_on = condvar->condID;
	pcb->state = 3;
	enqueue(pcb, condvar->condQueue);
}
