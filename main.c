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
#include "Leds.h"



ISR(TIMER1_CAPT_vect) {    // Timer1 Input Capture Interrupt (when Echo pin goes high or low)
    static uint16_t rising_edge_time = 0;
    
    if (TCCR1B & (1 << ICES1)) {
        // Rising edge: start the timer
        rising_edge_time = ICR1;  // Capture the timer value when Echo pin goes HIGH
        TCCR1B &= ~(1 << ICES1);  // Switch to falling edge (Echo pin goes LOW)
    } else {
        // Falling edge: capture the pulse duration
        pulse_duration = ICR1 - rising_edge_time;  // Calculate the duration of the pulse
        TCCR1B |= (1 << ICES1);  // Switch back to rising edge capture
    }
}



uint8_t findBestDirection() {
    uint16_t maxDistance = 0;
    uint8_t bestAngle = 255;  // No clear path

    for (int angle = 0; angle <= 180; angle ++) {
        OCR2 = angle+50;
        _delay_loop_2(0);
        uint16_t distance = calculate_distance();

        if (distance > maxDistance) {
            maxDistance = distance;
            
            bestAngle = angle;
        }
    }

    if (maxDistance < 15) {
        LED_ON(LED0);
        _delay_loop_2(0);
        LED_OFF(LED0);
        return 255;  // No path
    } 
    return bestAngle;
}


    
 

  
int main(void) {
    /* Replace with your application code */
    init_LCD4();
    init_ultrasonic_sensor();
    init_servo();
    initMotors();
    initLEDs();
  
    uint16_t pulse_duration;
    uint16_t distance; 
    LCD4_DATA_STR("left");
   while (1) {
      
     
        send_trigger_pulse();  

        distance = calculate_distance();  
         
        
       uint8_t bestDirection = findBestDirection();
       
        if (bestDirection == 255) {  // No clear path
            stopCar();
        }
        else {
            if (bestDirection > 90) {
                rotateRight();
                LCD4_CLEAR();
                LCD4_DATA_STR("Turn right");
            } else if (bestDirection < 90) {
                rotateLeft();
                LCD4_CLEAR();
                LCD4_DATA_STR("turn left");
            }
            moveForward();
            LCD4_CLEAR();
            LCD4_DATA_STR("moving forward");
        }
            
        }
                
       
      
        
   }

