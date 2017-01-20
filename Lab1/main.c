/*
 * main.c
 *
 *  Created on: Jan 17, 2017
 *      Author: Matt
 */
#include "RBELib/RBELib.h"

void part1();
void part2();
void WDT_off();

int main(){
	//Common setup here:
	WDT_off();

	//Interchange the correct part of the lab
	part1();
	return 1;
} /* End main */

//This does the first part of the lab
void part1(){

}

//This does the second part of the lab
void part2(){

}

void WDT_off(){
	__disable_interrupt();
	__watchdog_reset();
	/* Clear WDRF in MCUSR */
	MCUSR &= ~(1<<WDRF);
	/* Write logical one to WDCE and WDE */
	/* Keep old prescaler setting to prevent unintentional time-out */
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	/*Turn off WDT */
	WDTCSR = 0x00;
	__enable_interrupt();
}