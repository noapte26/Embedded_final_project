#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>
#include "myMotor.h"

void initMotors() {   // set motors pins as input
    DDRA |= (1 << MOTOR_LEFT_FORWARD) | (1 << MOTOR_LEFT_BACKWARD) |
            (1 << MOTOR_RIGHT_FORWARD) | (1 << MOTOR_RIGHT_BACKWARD);
}


void moveForward() {
    PORTA |= (1 << MOTOR_LEFT_FORWARD);
    PORTA &= ~(1 << MOTOR_LEFT_BACKWARD);
    PORTA |= (1 << MOTOR_RIGHT_FORWARD);
    PORTA &= ~(1 << MOTOR_RIGHT_BACKWARD);
}

void stopCar() {
    PORTA &= ~((1 << MOTOR_LEFT_FORWARD) | (1 << MOTOR_LEFT_BACKWARD) |
               (1 << MOTOR_RIGHT_FORWARD) | (1 << MOTOR_RIGHT_BACKWARD));
}

void rotateLeft() {
    stopCar();
    PORTA |= (1 << MOTOR_LEFT_BACKWARD);
    PORTA |= (1 << MOTOR_RIGHT_FORWARD);
    _delay_ms(500);
    stopCar();
}

void rotateRight() {
    stopCar();
    PORTA |= (1 << MOTOR_LEFT_FORWARD);
    PORTA |= (1 << MOTOR_RIGHT_BACKWARD);
    _delay_ms(500);
    stopCar();
}
