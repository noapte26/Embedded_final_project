/*
 * File:   main.c
 * Author: hebai
 *
 * Created on October 20, 2024, 11:37 AM
 */


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#include "DIO.h"
#include "MyINT0.h"

#define CONV_RATIO = 0.0010721875;
#define TRIG PIND0
#define ECHO  PIND2

static volatile int timer_value = 0;
static volatile int i=0;

ISR(INT0_vect){
    if(i==1){
        TCCR1B = 0;  //STOP COUNTER
        timer_value = TCNT1;   //TAKE THE VALUE FROM COUNTER
        TCNT1 = 0;  // SET COUNYER BACK TO ZERO
        i = 0;
    }
    if(i == 0){
        TCCR1B |= (1<<CS10); // START COUNTER1 WITH FREQ 16000 000
        i==1;
    }
}
int main(void) {
    /* Replace with your application code */
    setPIND_DIR(TRIG,OUT);  // SET TRIGGER PIN AS OUTPUT
    setPIND_DIR(ECHO,IN);    // SET ECHO PIN AS INPUT
            
    init_INT0(3);  //interrupt at any logical change
    int16_t distance =0;
    sei();
    while (1) {
        setPIND(TRIG, HIGH);
        _delay_ms(15);
        setPIND(TRIG, LOW);
        distance = timer_value * CONV_RATIO;
        
    }
}
