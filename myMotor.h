/* 
 * File:   myMotor.h
 * Author: hebai
 *
 * Created on December 9, 2024, 8:59 PM
 */

#ifndef MYMOTOR_H
#define	MYMOTOR_H

#define MOTOR_LEFT_FORWARD PA1
#define MOTOR_LEFT_BACKWARD PA0
#define MOTOR_RIGHT_FORWARD PA2
#define MOTOR_RIGHT_BACKWARD PA3

void initMotors();


void moveForward();

void stopCar();

void rotateLeft();

void rotateRight();

#endif	/* MYMOTOR_H */

