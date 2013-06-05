/*
 * main.c
 *
 *  Created on: Jun 3, 2013
 *      Author: TyPow, Herndon
 */

#include "Global.h"
#include "Process.h"
#include "PCB.h"
#include "Queue.h"
#include "Mutex.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

void *timerInterrupt();
void setGlobalVariables();

void setGlobalVariables(int argc, const char* argv[]) {
	int i;
	for(i = 1; i < argc; i+=2 )
	{
		if (i+1 < argc) { // check that num for argument exists
			if (strcmp( argv[i], "-k") == 0) {
				// keyboard input processes
				numOfKeyboardProc = atoi(argv[i+1]);
			} else if (strcmp( argv[i], "-p") == 0) {
				// compute bound process
				numOfProc = atoi(argv[i+1]);
			} else if (strcmp( argv[i], "-io") == 0) {
				// input/output bound process
				numOfIOProc = atoi(argv[i+1]);
			} else if (strcmp( argv[i], "-pc") == 0) {
				// producer consumer pairs
				numOfProducerConsumerProc = atoi(argv[i+1]);
			}
		}
	}

	// the values are correct
	if (numOfKeyboardProc > 0 && numOfProc > 0 && numOfProducerConsumerProc > 0 &&
			numOfKeyboardProc > 0 && numOfIOProc > 0) {
		// CONTINUE
	} else {
		// INCORRECT VALUE. throw exception?
	}
}

void *timerInterrupt(void) {
	while(1 == 1) {
		Sleep(3000);
		timerInt = 1;
	}
	return 0;
}

int main(int argc, const char* argv[]) {

	// Example for assignment: -p 22 -k 2 -io 3 -pc 3
	setGlobalVariables(argc, argv);

	pthread_t timer;
	pthread_create(&timer, NULL, timerInterrupt, NULL);
	//int i = 1;
	while(1 == 1) {
		if(timerInt == 1) {
			printf("Timer Interrupt\n");
			timerInt = 0;
		}
	}

	return 0;
}
