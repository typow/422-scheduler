/*
 * Queue.c
 *
 *  Created on: May 22, 2013
 *      Author: TyPow
 */

#include "Process.h"
#include "PCB.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


PCBQueuePtr queueConstructor() {
	printf("before q constructor\n");
	PCBQueuePtr queue = (PCBQueuePtr) malloc(sizeof(PCBQueue));
	queue->head = queue->tail = 0;
	queue->current_size = 0;
	queue->PCBarray[queue->head] = NULL;
	printf("end of q constructor\n");
	return queue;
}

PCBPtr dequeue(PCBQueuePtr pcbq) {
	 PCBPtr returnPCB = *pcbq->PCBarray[pcbq->head];
	 pcbq->PCBarray[pcbq->head] = NULL;
	 pcbq->head = (pcbq->head + 1) % 100;
	 pcbq->current_size--;
	 return returnPCB;
}

void enqueue(PCBPtr the_pcb, PCBQueuePtr pcbq) {
	*pcbq->PCBarray[pcbq->tail] = the_pcb;
	pcbq->tail = (pcbq->tail + 1) % 100;
	pcbq->current_size++;
}

bool isEmpty(PCBQueuePtr pcbq) {
	bool result = false;
	if(pcbq->PCBarray[pcbq->head] == NULL) {
		result = true;
	}
	return result;
}

bool isFull(PCBQueuePtr pcbq) {
	bool result = false;
	if(pcbq->current_size == 100) {
		result = true;
	}
	return result;
}

int main() {
	printf("in main before evrything\n");
	PCBQueuePtr pcbq = queueConstructor();
	PCBPtr pcb1 = pcbConstructor(1);
	PCBPtr pcb2 = pcbConstructor(2);
	PCBPtr pcb3 = pcbConstructor(3);
	enqueue(pcb1, pcbq);
	printf("expect 1: %d", dequeue(pcbq)->pid);
	enqueue(pcb1, pcbq);
	enqueue(pcb2, pcbq);
	printf("expect 2: %d", dequeue(pcbq)->pid);

	return 0;
}
