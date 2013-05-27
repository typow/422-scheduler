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
	PCBQueuePtr queue = (PCBQueuePtr) malloc(sizeof(PCBQueue));
	queue->head = queue->tail = 0;
	queue->current_size = 0;
	queue->PCBarray[queue->head] = NULL;
	return queue;
}

PCBPtr dequeue(PCBQueuePtr pcbq) {
	 PCBPtr returnPCB = pcbq->PCBarray[pcbq->head];
	 pcbq->PCBarray[pcbq->head] = NULL;
	 pcbq->head = (pcbq->head + 1) % 100;
	 pcbq->current_size--;
	 return returnPCB;
}

void enqueue(PCBPtr the_pcb, PCBQueuePtr pcbq) {
	pcbq->PCBarray[pcbq->tail] = the_pcb;
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
	PCBQueuePtr pcbq = queueConstructor();
	PCBPtr pcb1 = pcbConstructor(1);
	PCBPtr pcb2 = pcbConstructor(2);
	PCBPtr pcb3 = pcbConstructor(3);
	printf("isEmpty(expect 1)?: %d\n", isEmpty(pcbq));
	enqueue(pcb1, pcbq);
	printf("isEmpty(expect 0)?: %d\n", isEmpty(pcbq));
	printf("expect 1: %d\n", dequeue(pcbq)->pid);
	enqueue(pcb1, pcbq);
	enqueue(pcb2, pcbq);
	dequeue(pcbq);
	printf("expect 2: %d\n", dequeue(pcbq)->pid);
	printf("isEmpty(expect 1)?: %d\n", isEmpty(pcbq));
	int i;
	printf("isFull(expect 0)?: %d\n", isFull(pcbq));
	for(i = 0; i < 100; i++) {
		enqueue(pcb3, pcbq);
	}
	printf("isFull(expect 1)?: %d\n", isFull(pcbq));
	return 0;
}
