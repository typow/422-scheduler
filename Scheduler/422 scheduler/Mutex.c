/*
 * Mutex.c
 *
 *  Created on: Jun 2, 2013
 *      Author: TyPow
 */
#include "Process.h"
#include "PCB.h"
#include "Queue.h"
#include "Mutex.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Constructs a mutex that has an id its waiting queue and the current owner of the mutex.
 */
MutexPtr mutexConstructor(int mutex_ID, PCBQueuePtr mutexq) {
	MutexPtr mutex = (MutexPtr) malloc(sizeof(Mutex));
	mutex->mutexID = mutex_ID;
	mutex->mutexQueue = mutexq;
	return mutex;
}

/*
 * Changes the owner of the mutex to the next PCBPtr waiting at the head of the queue.
 */
void switchOwner(MutexPtr mutex) {
	mutex->ownerID->owns = 0;
	mutex->ownerID = dequeue(mutex->mutexQueue);
	mutex->ownerID->owns = mutex->mutexID;
}

/*
 * Adds the PCBPtr to the waiting queue for this mutex.
 */
void mutexWaiting(MutexPtr mutex, PCBPtr pcb) {
	pcb->waiting_on = mutex->mutexID;
	pcb->state = 3;
	enqueue(pcb, mutex->mutexQueue);
}
