#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include "myServo.h"



void init_servo(){
    //TIMER2_OC2_INIT();  // setting pD7 one
  
    TCCR2 |= (0 << WGM20) |(1 << WGM21); // CTC
    TCCR2 |= (1 << COM20) | (0<< COM21); // TOGGLE
    TCCR2 |= (1 << CS22) | (1 << CS21); // PRESCALER 256
    DDRD|=(1<<PD7);   //PWM Pins as Out
   
    
}

void  servo_rotate(){
    
    for(int i=50 ; i<=150 ; i++){
        OCR2 = i;
        _delay_loop_2(0);
       // _delay_loop_2(0);
       // _delay_loop_2(0);
    }
    for(int i = 150 ; i >= 50 ; i--){
        OCR2 = i;
        _delay_loop_2(0);
        //_delay_loop_2(0);
       // _delay_loop_2(0);
                
    }
}
/*void initServoTimer2() {
    DDRD |= (1 << PD7);  // Set SERVO_PIN (PD7) as output
    TCCR2 |= (1 << WGM20) | (1 << WGM21) | (1 << COM21) | (1 << CS21); // Fast PWM, non-inverting, Prescaler 8
    OCR2 = SERVO_MIN;  // Start at 0°
}

void setServoAngle(uint8_t angle) {
    uint8_t pulseWidth = SERVO_MIN + (angle * (SERVO_MAX - SERVO_MIN) / 180);
    OCR2 = pulseWidth;
    _delay_ms(500);  // Allow servo to reach position
}*/
