/*
 * Queue.c
 *
 *  Created on: May 22, 2013
 *      Author: TyPow
 */

#include "PCB.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


PCBQueuePtr constructor() {
	/*PCBQueuePtr pcb = (PCBQueuePtr) malloc(sizeof(PCBQueue));
	pcb->head = pcb->tail = 0;
	pcb->max_size = pcb->current_size = size;
	return pcb;*/
	//PCBQueue queue;
	PCBQueuePtr queue = (PCBQueuePtr) malloc(sizeof(PCBQueue));
	queue->head = queue->tail = 0;
	queue->current_size = 0;
	return queue;
}

PCBPtr dequeue(PCBQueuePtr pcbq) {
	 PCBPtr returnPCB = pcbq->PCBarray[pcbq->head];
	 pcbq->PCBarray[pcbq->head] = NULL;
	 pcbq->head = ((pcbq->head++) % 100);
	 return returnPCB;
}

void enqueue(PCBPtr the_pcb, PCBQueuePtr the_queue) {

}
