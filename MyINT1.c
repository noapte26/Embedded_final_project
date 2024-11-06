#include "MyINT1.h"
void INT1_selectMode(char INT_MODE){
       MCUCR &= 0XF3;
       switch(INT_MODE){
           case '1':
               MCUCR &= 0XF3;
               break;
           case '2':
               MCUCR |= ((0<<ISC11)|(1<<ISC10));
               break;
           case '3':
               MCUCR |= ((1<<ISC11)|(0<<ISC10));
               break;
           case '4':
               MCUCR |= ((1<<ISC11)|(1<<ISC10));
               break;
       }
   }
void init_INT1(char MODE){
    //SELECT MODE
    INT1_selectMode(MODE);
    GICR |= (1<<INT1);
    
    
}   
void INT1_DISABLE(){
    GICR &= ~(1<<INT1);
}
void INT1_changeMode(char INT_MODE){
    GICR &= ~(1<<INT1);
    INT1_selectMode(INT_MODE);
    GICR |= (1<<INT1);
}
