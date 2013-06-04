/*
 * main.c
 *
 *  Created on: Jun 3, 2013
 *      Author: TyPow
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

int main() {
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

void *timerInterrupt(void) {
	while(1 == 1) {
		Sleep(3000);
		timerInt = 1;
	}
	return 0;
}
