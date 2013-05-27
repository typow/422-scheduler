/*
 * PCB.c
 *
 *  Created on: May 26, 2013
 *      Author: TyPow
 */

#include "Process.h"
#include "PCB.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * Currently just used to test that queue works.
 */
PCBPtr pcbConstructor(int testnum) {
	PCBPtr pcb = (PCBPtr) malloc(sizeof(PCBStr));
	pcb->pid = testnum;
	return pcb;
}
