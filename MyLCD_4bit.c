#define F_CPU 16000000UL 
#include "MyLCD_4bit.h"
#include "MyDIO.h"
#include <util/delay.h>


void MYitoa(int value, char* str, int base) {
    char *ptr1 = str, tmp_char;
    int tmp_value;

    // Handle 0 explicitly
    if (value == 0) {
        *str++ = '0';
        *str = '\0';
        return;
    }

    // Handle negative numbers (base 10)
    int isNegative = 0;
    if (value < 0 && base == 10) {
        isNegative = 1;
        value = -value;
    }

    // Process each digit
    while (value != 0) {
        tmp_value = value % base;
        *str++ = (tmp_value < 10) ? (tmp_value + '0') : (tmp_value - 10 + 'A');
        value /= base;
    }

    // Add negative sign for base 10
    if (isNegative) {
        *str++ = '-';
    }

    // Null-terminate string
    *str = '\0';

    // Reverse the string
    while (ptr1 < --str) {
        tmp_char = *ptr1;
        *ptr1++ = *str;
        *str = tmp_char;
    }
}



void LCD4_EN(){
    LCD_CONTROL |= (1<<EN);
    _delay_us(50);
    LCD_CONTROL &= ~(1<<EN);
    _delay_ms(20);
}

void LCD4_COMMAND(char command){
    //SET RS TO 0
    LCD_CONTROL &= ~(1<<RS);
    LCD_PORT = (LCD_PORT & 0X0F) | (command & 0XF0);
    LCD4_EN();
    
    LCD_PORT = (LCD_PORT & 0X0F) | (command <<4);
    LCD4_EN();
    _delay_ms(20);
    
}
void LCD4_DATA(char data){
    LCD_CONTROL |= (1<<RS);
    LCD_PORT = (LCD_PORT & 0X0F) | (data & 0XF0);
    LCD4_EN();
    
    LCD_PORT = (LCD_PORT & 0X0F) | (data <<4);
    LCD4_EN();
    _delay_ms(20);
}
void init_LCD4(){
    // DIO
    setPORTC_DIR_VAL(0XF0, OUT);
    setPIND_DIR(RS, OUT);
    setPIND_DIR(RW, OUT);
    setPIND_DIR(EN, OUT);
    _delay_ms(20);
    //LCD SETUP
    setPIND(RS, LOW);
    //RETURN HOME
    LCD4_COMMAND(RETURN_HOME);
    //SET MODE
    LCD4_COMMAND(MODE_4BITS);
    //CURSOR SET &DISPLAY MODE
    LCD4_COMMAND(CURSOR_OFF_DISPLAY_ON);
    //CLEAR
    LCD4_COMMAND(CLEAR);
}
void LCD4_DATA_STR(char* str){
    int i = 0;
    while(str[i]){
        LCD4_DATA(str[i]);
        i++;
    }
}
void LCD4_DATA_NUM(int num){
    char str[11];
    MYitoa(num, str, 10);
    LCD4_DATA_STR(str);
    
}
void LCD4_CLEAR(){
    LCD_CONTROL &= ~(1<<RS);
    LCD_PORT = (LCD_PORT & 0X0F) | (CLEAR & 0XF0);
    LCD4_EN();
    
    LCD_PORT = (LCD_PORT & 0X0F) | (CLEAR <<4);
    LCD4_EN();
    _delay_ms(20);
}
