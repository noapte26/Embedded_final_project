#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include "myUltrasonic.h"



void init_ultrasonic_sensor() {
    DDRD |= (1 << TRIG_PIN);  // Set TRIG_PIN as output
    DDRD &= ~(1 << ECHO_PIN); // Set ECHO_PIN as input

    // Set up Timer1 in input capture mode
    TCCR1B |= (1 << ICES1);  // Capture on rising edge (Echo pin goes HIGH)
    TCCR1B |= (1 << CS11);   // Prescaler of 8 

    
    TIMSK |= (1 << TICIE1);  // Enable input capture interrupt
    sei();  
}

void send_trigger_pulse() {
    PORTD |= (1 << TRIG_PIN);  // Set the TRIG_PIN high
    _delay_us(10);             // Wait for 10µs
    PORTD &= ~(1 << TRIG_PIN); // Set the TRIG_PIN low
}


uint16_t calculate_distance() {
  
    
    return pulse_duration / CONV_RATIO;
}
