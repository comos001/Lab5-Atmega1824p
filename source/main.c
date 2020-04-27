/*	Author: comos001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; 
	DDRC = 0xFF; PORTC = 0x00;
	unsigned short sensor = 0x00;
	unsigned short output = 0x00;
    /* Insert your solution below */
	while (1) {
		PORTC = 0x00;
		output = 0x00;
		sensor = PINA & 0x0F;
		if ((sensor == 0)){
			output = 0x40;
		}
	
		else if ((sensor == 1) | (sensor == 2)){
			output = (output & 0x9F) | 0x60;
		}
		else if ((sensor == 3) | (sensor == 4)){
                        output = (output & 0x8F) | 0x70;
                }
		else if ((sensor == 6) | (sensor == 5)){
                        output = (output & 0xC7) | 0x38;
                }
		else if ((sensor == 7) | (sensor == 8) | (sensor == 9))		{
                        output = (output & 0xC2) | 0x3C;
                }
		else if ((sensor == 10) | (sensor == 11) | (sensor == 12))
		{
                        output = (output & 0xC1) | 0x3E;
                }
		else if ((sensor == 13) | (sensor == 14) | (sensor == 15)){
                        output = (output & 0xC0) | 0x3F;
                }
		else { 
			output = 0x00;
		}

	PORTC = output;
		

    }
    return 1;
}


