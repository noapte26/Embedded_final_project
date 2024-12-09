/* 
 * File:   Leds.h
 * Author: hebai
 *
 * Created on December 6, 2024, 3:14 PM
 */

#ifndef LEDS_H
#define	LEDS_H

#ifndef LLEDS_H
#define	LLEDS_H



#define LED0     PC2
#define LED1     PC7
#define LED2     PD3


void initLEDs(void);
void LED_ON(int LED_NUM);
void LED_OFF(int LED_NUM);

#endif	/* LEDS_H */

#endif	/* LEDS_H */

