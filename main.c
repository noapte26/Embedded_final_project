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

#include "MyDIO.h"
#include "MyINT0.h"
#include "MyTimers.h"
#include "MyLCD_4bit.h"
#define CONV_RATIO  0.01715
#define TRIG PIND0
#define ECHO  PIND2

static volatile uint16_t timer_value = 0;
static volatile uint8_t i=0;


void init_servo(){
    TIMER2_OC2_INIT();  // setting pD7 one
    initTimer2(3, 2);   // select fast PWM and Pre scalar of 8
    TIMER2_OC2_SELSECTMODE(OC2_FAST_PWM_NONINVERTING);
    
}
void set_servo_angel(uint8_t degree){
    OCR2 = (degree* (16-8) /180) +8;
}
void servo_rotate(){
    uint8_t degree;
    for(degree=0 ; degree<=180 ; degree+=10){
        set_servo_angel(degree);
        _delay_ms(100);
    }
    for(degree = 180 ; degree >= 0 ; degree-=10){
        set_servo_angel(degree);
        _delay_ms(100);
    }
}
ISR(INT0_vect){
    if(i==1){
        TCCR1B = 0;  //STOP COUNTER
        timer_value = TCNT1;   //TAKE THE VALUE FROM COUNTER
        TCNT1 = 0;  // SET COUNYER BACK TO ZERO
        i = 0;
    }
    if(i == 0){
        TCCR1B |= (1<<CS10); // START COUNTER1 WITH FREQ 16000 000
        i=1;
    }
}
void init_ultraSonic(){
    setPIND_DIR(TRIG,OUT);  // SET TRIGGER PIN AS OUTPUT
    setPIND_DIR(ECHO,IN);    // SET ECHO PIN AS INPUT
            
    init_INT0(3);  //interrupt at any logical change
    
    sei();
}
void ultra_measure_disblay_distance(){
    uint16_t distance =0;
    
    setPIND(TRIG, HIGH);   //send signal to trigger
    _delay_us(10);
    setPIND(TRIG, LOW);
    _delay_ms(60); 
    
    if(timer_value > 0){
        distance = timer_value * CONV_RATIO;
        LCD4_CLEAR();
        LCD4_DATA_STR("Distance:");
        LCD4_DATA_NUM(distance);
        LCD4_DATA_STR("cm");
        
        timer_value = 0;
    }
    
    
    
    
}
int main(void) {
    /* Replace with your application code */
    init_LCD4();
    init_ultraSonic();
    
   //LCD4_DATA_STR("Ultrasonic Test");
    while (1) {
        ultra_measure_disblay_distance();
        _delay_ms(500);
        
    }
}
