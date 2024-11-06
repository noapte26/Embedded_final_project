#include"MyTimers.h"
#include "MyDIO.h"



void initTimer0(char timerMode, char clock) {
    TIMER0_SELECTMODE(timerMode);
    TIMER0_SELECTCLK(clock);

}

void TIMER0_SELECTMODE(char timerMode) {
    TCCR0 &= ~((1 << WGM00) | (1 << WGM01));
    switch (timerMode) {
        case 0:
            TCCR0 |= ((0 << WGM00) | (0 << WGM01));
            TIMER0_TOVI_EN();
            break;
        case 1:
            TCCR0 |= ((1 << WGM00) | (0 << WGM01));
            break;
        case 2:
            TCCR0 |= ((0 << WGM00) | (1 << WGM01));
            TIMER0_OCI_EN();
            //OCR0 = TIMER0_OCR_VAL;

            break;
        case 3:
            TCCR0 |= ((1 << WGM00) | (1 << WGM01));
            break;

    }
}

void TIMER0_SELECTCLK(char clock) {
    TCCR0 &= ~((1 << CS02) | (1 << CS01) | (1 << CS00));
    TCCR0 |= clock;
}

void TIMER0_TOVI_EN() {
    TIMSK |= (1 << TOIE0);
}

void TIMER0_OCI_EN() {
    TIMSK |= (1 << OCIE0);
}

void TIMER0_OCO_INIT() {
    setPINB_DIR(OC0, OUT);
    
}

void TIMER0_OC0_SELSECTMODE(char mode) {
    TCCR0 &= ~((1 << COM00) | (1 << COM01));
    TCCR0 |= (mode << 4);
}


void initTimer2(char timerMode, char clock) {
    TIMER2_SELECTMODE(timerMode);
    TIMER2_SELECTCLK(clock);

}

void TIMER2_SELECTMODE(char timerMode) {
    TCCR2 &= ~((1 << WGM20) | (1 << WGM21));
    switch (timerMode) {
        case 0:
            TCCR2 |= ((0 << WGM20) | (0 << WGM21));
            TIMER0_TOVI_EN();
            break;
        case 1:
            TCCR2 |= ((1 << WGM20) | (0 << WGM21));
            break;
        case 2:
            TCCR2 |= ((0 << WGM20) | (1 << WGM21));
            TIMER2_OCI_EN();
            OCR2 = TIMER0_OCR_VAL;

            break;
        case 3:
            TCCR2 |= ((1 << WGM20) | (1 << WGM21));
            break;

    }
}

void TIMER2_SELECTCLK(char clock) {
    TCCR2 &= ~((1 << CS22) | (1 << CS21) | (1 << CS20));
    TCCR2 |= clock;
}

void TIMER2_TOV2_EN() {
    TIMSK |= (1 << TOIE2);
}

void TIMER2_OC2_EN() {
    TIMSK |= (1 << OCIE2);
}

void TIMER2_OC2_INIT() {
    setPIND_DIR(PD7, OUT);
    
}

void TIMER2_OC2_SELSECTMODE(char mode) {
    TCCR2 &= ~((1 << COM20) | (1 << COM21));
    TCCR2 |= (mode << 4);
}




void initTimer1(char timerMode, char clock) {
    TIMER1_SELECTMODE(timerMode);
    TIMER1_SELECTCLK(clock);

}
void TIMER1_SELECTMODE(char timerMode) {
    TCCR1A &= ~((1 << WGM10) | (1 << WGM11));
    TCCR1B &= ~((1 << WGM00) | (1 << WGM01));
    switch (timerMode) {
        case 0:
            TCCR1A |= ((0 << WGM10) | (0 << WGM11));
            TCCR1B |= ((0 << WGM12) | (0 << WGM13));
            //TIMER1_TOVI_EN();
            break;
        case 1:
            TCCR1A |= ((1 << WGM10) | (0 << WGM11));
            TCCR1B |= ((0 << WGM12) | (0 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_OCIB_EN();
            OCR1B = TIMER1_OCR1B_VAL;
            break;
        case 2:
            TCCR1A |= ((0 << WGM10) | (1 << WGM11));
            TCCR1B |= ((0 << WGM12) | (0 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;


            break;
        case 3:
            TCCR1A |= ((1 << WGM10) | (1 << WGM11));
            TCCR1B |= ((0 << WGM12) | (0 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_OCIB_EN();
            TIMER1_OCIA_EN();
            OCR1B = TIMER1_OCR1B_VAL;
            OCR1A = TIMER1_OCR1A_VAL;
            break;
        case 4:
            TCCR1A |= ((0 << WGM10) | (0 << WGM11));
            TCCR1B |= ((1 << WGM12) | (0 << WGM13));
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            break;
        case 5:
            TCCR1A |= ((1 << WGM10) | (0 << WGM11));
            TCCR1B |= ((1 << WGM12) | (0 << WGM13));
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            TIMER1_TOVI_EN();
            TIMER1_OCIB_EN();
            OCR1B = TIMER1_OCR1B_VAL;
            break;
        case 6:
            TCCR1A |= ((0 << WGM10) | (1 << WGM11));
            TCCR1B |= ((1 << WGM12) | (0 << WGM13));
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            TIMER1_TOVI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1B = TIMER1_OCR1B_VAL;
            OCR1A = TIMER1_OCR1A_VAL;
            break;
        case 7:
            TCCR1A |= ((1 << WGM10) | (1 << WGM11));
            TCCR1B |= ((1 << WGM12) | (0 << WGM13));
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            TIMER1_TOVI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1B = TIMER1_OCR1B_VAL;
            OCR1A = TIMER1_OCR1A_VAL;
            break;
        case 8:
            TCCR1A |= ((0 << WGM10) | (0 << WGM11));
            TCCR1B |= ((0 << WGM12) | (1 << WGM13));
            break;
        case 9:
            TCCR1A |= ((1 << WGM10) | (0 << WGM11));
            TCCR1B |= ((0 << WGM12) | (1 << WGM13));
            break;
        case 10:
            TCCR1A |= ((0 << WGM10) | (1 << WGM11));
            TCCR1B |= ((0 << WGM12) | (1 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_ICI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            break;
        case 11:
            TCCR1A |= ((1 << WGM10) | (1 << WGM11));
            TCCR1B |= ((0 << WGM12) | (1 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            break;
        case 12:
            TCCR1A |= ((0 << WGM10) | (0 << WGM11));
            TCCR1B |= ((1 << WGM12) | (1 << WGM13));
            TIMER1_ICI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            ICR1 = TIMER1_ICR_VAL;
            break;
        case 13:
            TCCR1A |= ((1 << WGM10) | (0 << WGM11));
            TCCR1B |= ((1 << WGM12) | (1 << WGM13));
            break;
        case 14:
            TCCR1A |= ((0 << WGM10) | (1 << WGM11));
            TCCR1B |= ((1 << WGM12) | (1 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_ICI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;
            ICR1 = TIMER1_ICR_VAL;

            break;
        case 15:
            TCCR1A |= ((1 << WGM10) | (1 << WGM11));
            TCCR1B |= ((1 << WGM12) | (1 << WGM13));
            TIMER1_TOVI_EN();
            TIMER1_OCIA_EN();
            TIMER1_OCIB_EN();
            OCR1A = TIMER1_OCR1A_VAL;
            OCR1B = TIMER1_OCR1B_VAL;

            break;

    }
}

void TIMER1_SELECTCLK(char clock) {
    TCCR1B &= ~((1 << CS12) | (1 << CS11) | (1 << CS10));
    TCCR0 |= clock;
}

void TIMER1_TOVI_EN() {
    TIMSK |= (1 << TOIE1);
}

void TIMER1_OCIA_EN() {
    TIMSK |= (1 << OCIE1A);
}

void TIMER1_OCIB_EN() {
    TIMSK |= (1 << OCIE1B);
}

void TIMER1_ICI_EN() {
    TIMSK |= (1 << TICIE1);
}

void TIMER1_SET_INPUT_CAPTURE(char edge) {
    TCCR1B |= (1 << ICNC1); // NOISE CANCELER
    switch (edge) {
        case 0:
            TCCR1B &= ~(1 << ICES1);
            break;
        case 1:
            TCCR1B |= (1 << ICES1);
    }
}

void TIMER1_OC1A_B_INIT() {
    setPIND_DIR(4, OUT);
    setPIND_DIR(5, OUT);
}

void TIMER1_OC1A_SELSECTMODE(char mode) {
    TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0));
    TCCR1A |= (mode << 6);
}

void TIMER1_OC1B_SELSECTMODE(char mode) {
    TCCR1A &= ~((1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0));
    TCCR1A |= (mode << 4);
}
