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
#define CONV_RATIO  58 //0.000107375
#define TRIG_PIN PD2
#define ECHO_PIN  PD6

static volatile int timer_value = 0;
static volatile int i = 0;
static volatile int overflow_count = 0;

volatile uint16_t pulse_duration = 0;  // To store the pulse duration
volatile uint8_t echo_flag = 0;        // Flag to indicate when the echo has been received



// Function to initialize the ultrasonic sensor
void init_ultrasonic_sensor() {
    DDRD |= (1 << TRIG_PIN);  // Set TRIG_PIN as output
    DDRD &= ~(1 << ECHO_PIN); // Set ECHO_PIN as input

    // Set up Timer1 in input capture mode
    TCCR1B |= (1 << ICES1);  // Capture on rising edge (Echo pin goes HIGH)
    TCCR1B |= (1 << CS11);   // Prescaler of 8 (Timer counts faster)

    // Enable input capture interrupt for Timer1
    TIMSK |= (1 << TICIE1);
    sei();  // Enable global interrupts
}

// Function to send a 10µs pulse on the TRIG_PIN
void send_trigger_pulse() {
    PORTD |= (1 << TRIG_PIN);  // Set the TRIG_PIN high
    _delay_us(10);             // Wait for 10µs
    PORTD &= ~(1 << TRIG_PIN); // Set the TRIG_PIN low
}

// Function to calculate the distance
uint16_t calculate_distance() {
    // Pulse duration in microseconds, distance in cm
    
    return pulse_duration / CONV_RATIO;
}

// Timer1 Input Capture Interrupt (when Echo pin goes high or low)
ISR(TIMER1_CAPT_vect) {
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


void init_servo(){
    //TIMER2_OC2_INIT();  // setting pD7 one
  
    TCCR2 |= (0 << WGM20) |(1 << WGM21); // CTC
    TCCR2 |= (1 << COM20) | (0<< COM21); // TOGGLE
    TCCR2 |= (1 << CS22) | (1 << CS21); // PRESCALER 256
    DDRD|=(1<<PD7);   //PWM Pins as Out
   
    
}

void servo_rotate(){
    
    for(int i=50 ; i<=150 ; i++){
        OCR2 = i;
        _delay_loop_2(0);
        _delay_loop_2(0);
        _delay_loop_2(0);
    }
    for(int i = 150 ; i >= 50 ; i--){
        OCR2 = i;
        _delay_loop_2(0);
        _delay_loop_2(0);
        _delay_loop_2(0);
                
    }
}


    
 

  
int main(void) {
    /* Replace with your application code */
    init_LCD4();
    init_ultrasonic_sensor();
    //init_ultraSonic();
    uint16_t pulse_duration;
    uint32_t distance;
    
    
      
   
    while (1) {
      
        send_trigger_pulse();  // Trigger the ultrasonic sensor
        _delay_ms(60);         // Wait for the sensor to settle

        distance = (calculate_distance())/2;  // Calculate the distance
        LCD4_CLEAR();
        LCD4_DATA_NUM(distance);  // Display the distance
        _delay_ms(500);  // Delay between readings
       
       
      
        
    }
}
