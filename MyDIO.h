/* 
 * File:   MyDIO.h
 * Author: hebai
 *
 * Created on October 27, 2024, 11:18 PM
 */

#ifndef MYDIO_H
#define	MYDIO_H



#include<avr/io.h>

#define OUT      1
#define IN       0

#define HIGH     1
#define LOW      0

#define ON       1
#define OFF      0
/**
 * 
 * @param pinNum pin number
 * @param state (IN , OUT) options
 * @return void
 */

void setPORTA_DIR_VAL(int val, int state);  // FOR CONFIGURING THE DIRECTION OF MORE THAN 1 PIN IN THE PORT
void setPORTB_DIR_VAL(int val, int state);
void setPORTC_DIR_VAL(int val, int state);
void setPORTD_DIR_VAL(int val, int state);

/**
 * 
 * @param pinNum
 * @param state
 * @return 
 */
void setPINA_DIR(int pinNum, int state);   // FOR CONFIGURING THE DIRECTION OF ONE PIN IN THE PORT
void setPINB_DIR(int pinNum, int state) ;
void setPINC_DIR(int pinNum, int state);
void setPIND_DIR(int pinNum, int state) ;

/**
 * 
 * @param state
 */
void setPORTA_DIR(int state);       //SETS ALL THE PORT AS INPUT OR OUTPUT
void setPORTB_DIR(int state);
void setPORTC_DIR(int state);
void setPORTD_DIR(int state);


/**
 * 
 * @param val
 */
void setPORTA_VAL(int val);   // FOR SETTING THE WHOLE PORT TO A GIVEN VALUE
void setPORTB_VAL(int val);
void setPORTC_VAL(int val);
void setPORTD_VAL(int val);

/**
 * 
 * @param pinNUM
 * @param status
 */
void setPINA(int pinNUM, int status);    // FOR SETTING THE VALUE OF ONE PIN IN THE PORT AS HIGH OR LOW
void setPINB(int pinNUM, int status);
void setPINC(int pinNUM, int status);
void setPIND(int pinNUM, int status);

char readPORTA();     //FOR REDING THE 8-BITS OF THE PORT
char readPORTB();
char readPORTC();
char readPORTD();

char readPINA(int pinNum);    //FOR READING ONE PIN IN THE PORT
char readPINB(int pinNum);
char readPINC(int pinNum);
char readPIND(int pinNum);




#endif	/* MYDIO_H */

