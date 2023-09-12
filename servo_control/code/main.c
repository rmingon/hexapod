 #include <avr/io.h>
 #include <stdbool.h>
 #include <avr/interrupt.h>
 unsigned char nb=0;
 volatile unsigned char vPORTB=1; // cette variable peut être évitée
 /*********************************************************************
 Interrupt Routine
 **********************************************************************/
 // timer1 overflow
 ISR(TIMER1_OVF_vect) {
   vPORTB ^= 0x01;
   PORTB = vPORTB;
 }

 /**********************************************************************
 Main
 **********************************************************************/
 int main( void ) {
 // Configure PORTB as output
     DDRB = 0xFF;
     PORTB = 0xFF;
 // enable timer overflow interrupt for both Timer0
     TIMSK |= (1<<TOIE1);
 // set timer0 counter initial value to 0
     TCNT1=0x0000;
 // start timer0 with 1024 prescaler
     TCCR1B = (1<<CS12) | (1<<CS10);
 // enable interrupts
     sei();
     while(true) { // grace a stdbool.h
     }
 }
