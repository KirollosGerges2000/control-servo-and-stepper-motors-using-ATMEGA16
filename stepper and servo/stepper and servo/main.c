/*
 * stepper and servo.c
 *
 * Created: 2/29/2024 9:50:30 AM
 * Author : Kirollos
 */ 

#include <avr/io.h>
#include "stepper_servo.h"



int main(void)
{
    /* Replace with your application code */
	DDRB=0x00;
	init_servo();
	init_bipolar();
init_unipolar();
    while (1) 
    {
		if(PINB&(1<<0))
		{
				SERVO();
				PORTC=0x00;
				PORTA=0x00;
				
		}
else if(PINB&(1<<1))
{
	bi_polar();
		PORTA=0x00;
		PORTD=0x00;
	
}
else if(PINB&(1<<2))
{
	uni_polar ();
		PORTC=0x00;
		PORTD=0x00;

}

else {
	
	PORTC=0x00;
	PORTD=0x00;
	PORTA=0x00;
	
}
    }
	return 0;
}

