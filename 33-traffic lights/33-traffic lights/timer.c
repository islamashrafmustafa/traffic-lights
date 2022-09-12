/*
 * timer.c
 *
 * Created: 8/19/2022 8:38:41 AM
 *  Author: Islam Ashraf Mustafa
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"


void timer_CTC_init_interrupt(void)
{
	// wave generation mode
	SET_BIT(TCCR0,WGM01);
	// load value in OCR0
	OCR0=78;
	// clock select
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	sei();
	// interrupt mask register
	SET_BIT(TIMSK,OCIE0);
}

void timer_wave_non_PWM()
{
	// set oc0 as output pin
	SET_BIT(DDRB,3);
	// select  CTC mode
	SET_BIT(TCCR0,WGM01);
	// load a value in OCR0	
	OCR0=64;
	//select timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// toggle OC0 on compare match 
	SET_BIT(TCCR0,COM00);
}

