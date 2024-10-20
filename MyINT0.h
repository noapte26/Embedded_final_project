/* 
 * File:   MyINT0.h
 * Author: hebai
 *
 * Created on October 20, 2024, 12:02 PM
 */

#ifndef MYINT0_H
#define	MYINT0_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#define INT_LOW_LEVEL 1
#define INT_CHANGE   2
#define INT_FALLING_EDGE 3
#define INT_RISING_EDGE 4



void INT0_selectMode(char INT_MODE);
void init_INT0(char MODE);
void INT0_DISABLE();
void INT0_changeMode(char INT_MODE);

#endif	/* MYINT0_H */

