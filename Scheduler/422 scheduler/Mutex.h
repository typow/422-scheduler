/*
 * Mutex.h
 *
 *  Created on: May 22, 2013
 *      Author: TyPow
 */


typedef struct {
	int mutexID; //The int ID for the Mutex that this object belongs to
	PCBPtr ownerID; //The current holder of the Mutex
	PCBQueuePtr mutexQueue; //The queue of processes waiting on the Mutex
} Mutex, *MutexPtr;


MutexPtr mutexConstructor(int, PCBQueuePtr); // creates the Mutex pass in the ID of the Mutex and the Mutex queue
void switchOwner(MutexPtr);	//takes the PCB at the head of the queue and makes in the owner
void mutexWaiting(MutexPtr, PCBPtr);
