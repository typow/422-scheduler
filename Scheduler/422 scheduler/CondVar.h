/*
 * CondVar.h
 *
 *  Created on: May 26, 2013
 *      Author: TyPow
 */

typedef struct {
	int condID; //The int ID for the condition variable that this object belongs to
	PCBPtr ownerID; //The current holder of the variable
	PCBQueue condQueue; //The queue of processes waiting on the variable
} CondVar, *CondVarPtr;


CondVarPtr mutexConstructor(int, PCBQueuePtr); // creates the Condition Variable pass
										 //in the ID of the variable and the condition queue
void switchOwner(CondVarPtr);	//takes the PCB at the head of the queue and makes in the owner
