/*
 * Queue
 *
 *  Created on: May 22, 2013
 *      Author: TyPow
 */

#define QUEUE_SIZE = 100

typedef enum {false=0, true=1} bool;


typedef struct {
	PCBPtr *PCBarray[100];
	int head;
	int tail;
	int current_size;
} PCBQueue;


typedef PCBQueue *PCBQueuePtr;

void enqueue(PCBPtr, PCBQueuePtr);
PCBPtr dequeue();
PCBQueuePtr constructor();
bool isEmpty();
bool isFull();
