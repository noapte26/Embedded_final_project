/* 
 * File:   MyLCD_4bit.h
 * Author: hebai
 *
 * Created on October 27, 2024, 11:04 PM
 */

#ifndef MYLCD_4BIT_H
#define	MYLCD_4BIT_H

#define LCD_PORT_DIR DDRC
#define LCD_PORT PORTC
#define RS PD1
#define RW PD4
#define EN PD5
#define LCD_CONTROL PORTD
#define LCD_CONTROL_DIR DDRD


 // LCD COMMAND CODES
#define CLEAR   0X01
#define MODE_8BITS 0X38
#define MODE_4BITS  0X28
#define RETURN_HOME 0X02
#define CURSOR_OFF_DISPLAY_ON  0X0C
#define ENTRY_MODE 0X06

void MYitoa(int, char*, int);
void init_LCD4();
void LCD4_COMMAND(char command);
void LCD4_DATA(char data);
void LCD4_EN();
void LCD4_DATA_STR(char*);
void LCD4_DATA_NUM(int num);
void LCD4_CLEAR();

#endif	/* MYLCD_4BIT_H */

