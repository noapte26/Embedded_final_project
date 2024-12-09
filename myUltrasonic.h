/* 
 * File:   myUltrasonic.h
 * Author: hebai
 *
 * Created on December 9, 2024, 9:09 PM
 */

#ifndef MYULTRASONIC_H
#define	MYULTRASONIC_H


#define CONV_RATIO  58/2 //0.000107375
#define TRIG_PIN PD2
#define ECHO_PIN  PD6

static volatile int timer_value = 0;
static volatile int i = 0;
static volatile int overflow_count = 0;

volatile uint16_t pulse_duration = 0;  // To store the pulse duration
volatile uint8_t echo_flag = 0;        // Flag to indicate when the echo has been received


void init_ultrasonic_sensor();

void send_trigger_pulse();


uint16_t calculate_distance();

#endif	/* MYULTRASONIC_H */

