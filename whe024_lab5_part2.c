/* Author: whe024
 * Partner(s) Name: Wentao He 
 * Lab Section: A21
 * Assignment: Lab #5  Exercise #2
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States {INIT, START, INCR, DECR, RESET} state;
unsigned char tmpC = 0x00;

void Tick()
{
    switch (state){
                case INIT :
                        state = START;
                break;
                case START :
                        if((~PINA & 0x01) == 0x01){
                                state = INCR;
                        }
                        if((~PINA & 0x02) == 0x02){
                                state = DECR;
                        }
                        if((~PINA & 0x03) == 0x03){
                                state = RESET;
                        }
		break;
                case INCR :
                        state = START;
                break;
                case DECR :
                        state = START;
                break;
                case RESET :
                        state = START;
                break;
                default:

                break;
        }

        switch (state){
		case INIT :
			tmpC = 0x00;
		break;
		case START :
		
		break;
		case INCR :
			tmpC++;
		break;
		case DECR :
			tmpC--;
		break;
		case RESET :
			tmpC = 0x00;
		break;
		default:
		
		break;
	}
	PORTC = tmpC;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    while (1) {
	while (1) {
	 Tick();
	}
    }
    return 1;
}
