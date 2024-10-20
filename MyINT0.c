#define F_CPU 16000000UL

#include "MyINT0.h"

void INT0_selectMode(char INT_MODE){
       MCUCR &= 0XFC;
       switch(INT_MODE){
           case '1':
               MCUCR |= ((0<<ISC01)|(0<<ISC00));
               break;
           case '2':
               MCUCR |= ((0<<ISC01)|(1<<ISC00));
               break;
           case '3':
               MCUCR |= ((1<<ISC01)|(0<<ISC00));
               break;
           case '4':
               MCUCR |= ((1<<ISC01)|(1<<ISC00));
               break;
       }
   }  

void init_INT0(char MODE){
    //SELECT MODE
    INT0_selectMode( MODE);
    GICR |= (1<<INT0);
}

void INT0_DISABLE(){
    GICR &= ~(1<<INT0);
}

void INT0_changeMode(char INT_MODE){
    GICR &= ~(1<<INT0);
    INT0_selectMode(INT_MODE);
    GICR |= (1<<INT0);
}

