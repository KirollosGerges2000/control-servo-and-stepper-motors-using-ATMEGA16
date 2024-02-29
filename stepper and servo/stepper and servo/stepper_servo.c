/*
 * stepper_servo.c
 *
 * Created: 2/29/2024 9:51:15 AM
 *  Author: Kirollos
 */ 
#include <avr/io.h>
#include "stepper_servo.h"
#include <util\delay.h>

void init_servo(void)
{
	DDRD=0x80;
	PORTD=0x00;
	
}
void init_bipolar(void)
{
	DDRC=0x0F;
	PORTC=0x0F;
	
}

void init_unipolar(void)
{
	DDRA=0xFF;
	PORTA=0x00;
	
}


void SERVO (void)
{
	//0
	PORTD=0x80;
	_delay_ms(10);
	PORTD=0x00;
	_delay_ms(10);
	
	_delay_ms(6000);
	 //-45
		PORTD=0x80;  
		_delay_ms(5);
		PORTD=0x00;
		_delay_ms(15);
		
		_delay_ms(6000);
		 //-90
			PORTD=0x80; 
			_delay_ms(0);
			PORTD=0x00;
			_delay_ms(20);
			
			_delay_ms(6000);
			//90
			PORTD=0x80;   
			_delay_ms(20);
			PORTD=0x00;
			_delay_ms(0);
			
			_delay_ms(6000);
			//45
			PORTD=0x80;   
			_delay_ms(15);
			PORTD=0x00;
			_delay_ms(20);
			
			_delay_ms(6000);
			
			
			
}
/*
A bipolar stepper motor has one winding per phase, 
without a center tap.
 The current must be reversed in the whole winding to change the polarity of the magnetic field. 
 A bipolar stepper motor requires a more complex driver circuit 
 that can reverse the current direction in each winding,
  usually using an H-bridge arrangement.
*/

void bi_polar (void)
{
		PORTC=0x02; //180 degree 
		_delay_ms(6000);
		PORTC=0x04;//90 degree 
		_delay_ms(6000);
	PORTC=0x08;//-90 degree 
	_delay_ms(6000);
	PORTC=0x01;//0 degree 
	_delay_ms(6000);
}


/*
A unipolar stepper motor has two windings per phase,
 each with a center tap that is connected to a common power supply.
  The current can flow in either direction through each half of the winding,
   creating four possible states for each phase.
    A unipolar stepper motor can be driven by a simple transistor circuit 
	that switches the current on and off in each half of the winding.
*/
void uni_polar (void)
{

	PORTA=0x02; //-90 degree
	_delay_ms(6000);
	PORTA=0x04;//+38 degree
	_delay_ms(6000);
	PORTA=0x08;//-142 degree
	_delay_ms(6000);
	PORTA=0x10;//-270 degree
	_delay_ms(6000);
	PORTA=0x20;//-38 degree
	_delay_ms(6000);
	PORTA=0x01;//+218 degree
	_delay_ms(6000);
	PORTA=0x00;//the same degree state
	_delay_ms(6000);

	
}