/*
 * 33-traffic lights.c
 *
 * Created: 8/21/2022 11:52:35 AM
 * Author : Islam Ashraf Mustafa
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include "LCD.h"
#include "LED.h"
#include "timer.h"


volatile unsigned char count1=0;
volatile unsigned char count_green=10;
volatile unsigned char count_yellow=5;
volatile unsigned char count_red=7;

int main(void)
{
   LCD_vInit();
   LED_vInit('D',0);
   LED_vInit('D',1);
   LED_vInit('D',2);
   timer_CTC_init_interrupt();
    while (1) 
    {
		count_green=10;
		count_yellow=5;
		count_red=7;
		LCD_clearscreen();
		LCD_vSend_string("remaining 10 sec");
		LED_vTurnOn('D',0);
		while (count_green>0)
		{
			if (count1>=100)
			{
				count1=0;
				count_green--;
				LCD_movecursor(1,11);
				LCD_vSend_char(' ');
				LCD_vSend_char(count_green+48);
			}
		}
		_delay_ms(500);
		LED_vTurnOff('D',0);
		LED_vTurnOn('D',1);
		LCD_clearscreen();
		LCD_vSend_string("remaining  5 sec");
		while (count_yellow>0)
		{
			if (count1>=100)
			{
				count1=0;
				count_yellow--;
				LCD_movecursor(1,11);
				LCD_vSend_char(' ');
				LCD_vSend_char(count_yellow+48);
			}
		}
		_delay_ms(500);
		LED_vTurnOff('D',1);
		LED_vTurnOn('D',2);
		LCD_clearscreen();
		LCD_vSend_string("remaining  7 sec");
		while (count_red>0)
		{
			if (count1>=100)
			{
				count1=0;
				count_red--;
				LCD_movecursor(1,11);
				LCD_vSend_char(' ');
				LCD_vSend_char(count_red+48);
			}
		}
		_delay_ms(500);
		LED_vTurnOff('D',2);
    }
}

ISR(TIMER0_COMP_vect)
{
	count1++;
}