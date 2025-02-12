/*
 * LCD final.c
 *
 * Created: 12-03-2021 12:46:02
 * Author : Tamanna Dave
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC=0b0000101;
	DDRD=0b11111111;
	
	PORTD=0X38;  //COMMAND FOR SELECTING 8 BIT MODE
	PORTC=0b0000100;  //COMMAND REGISTER IS SELECTED
	_delay_ms(100);
	PORTC=0b0000000;
	
	PORTD=0X0E;  //COMMANDFOR LCD ON CURSOR ON
	PORTC=0b0000100; //COMMAND REGISTER IS SELECTED
	_delay_ms(100);
	PORTC=0b0000000; 
	
	PORTD=0X01;  //COMMAND FOR CLEAR CURRENT SCREEN
	PORTC=0b0000100; //COMMAND REGISTER IS SELECTED
	_delay_ms(100);
	PORTC=0b0000000;
	
	PORTD=0X80;  //COMMAND TO SET POSITION OF CHARACTER TO DISPLAY
	PORTC=0b0000100; //COMMAND REGISTER IS SELECTED
	_delay_ms(100);
	PORTC=0b0000000;
	
	while(1)
	{
		PORTD='A';  //DATA TO DISPLAY ON LCD
		PORTC=0b0000101;
		_delay_ms(100);
		PORTC=0b0000001;
		
		_delay_ms(1000);
		
		PORTD=' ';  //DATA TO DISPLAY ON LCD
		PORTC=0b000101;
		_delay_ms(100);
		PORTC=0b000001;
		
		PORTD='B';  //DATA TO DISPLAY ON LCD
		PORTC=0b000101;
		_delay_ms(100);
		PORTC=0b000001;
		
		PORTD=' ';  //DATA TO DISPLAY ON LCD
		PORTC=0b000101;
		_delay_ms(100);
		PORTC=0b000001;
		
		PORTD=0X01;
		PORTC=0b0000100;
		_delay_ms(1000);
		PORTC=0b0000001;
	}
}

