#include <avr/io.h>
#include "DIO.h"
#include"std_macros.h"
void DIO_vsetPINDir(unsigned char portname,unsigned char pinnumber,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		if(direction==1)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);
		}
		break;
		case 'B':
		if(direction==1)
		{
			SET_BIT(DDRB,pinnumber);
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);
		}
		break;
		case 'C':
		if (direction==1)
		{
			SET_BIT(DDRC,pinnumber);
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);
		}
		break;
		case 'D':
		if (direction==1)
		{
			SET_BIT(DDRD,pinnumber);
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);
		}
		break;
		default:
		break;
	}
}
 void DIO_write(unsigned char portname,unsigned char pinnumber,unsigned char outputvalue)
 {
	 switch(portname)
	 {
		case 'A':
		if(outputvalue==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		if(outputvalue==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		if(outputvalue==1)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		if(outputvalue==1)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		default: break;
	 }
 }
unsigned char DIO_U8read(unsigned char portname,unsigned char pinnumber)
{
	unsigned char return_value;
	switch(portname)
	{
		case 'A':
		return_value=READ_BIT(PINA,pinnumber);
		break;
		case 'B':
		return_value=READ_BIT(PINB,pinnumber);
		break;
		case 'C':
		return_value=READ_BIT(PINC,pinnumber);
		break;
		case 'D':
		return_value=READ_BIT(PIND,pinnumber);
		break;
		default: break;
	}
	return return_value;
}
void DIO_toggle(unsigned char portname,unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		TOG_BIT(PORTA,pinnumber);
		break;
		case 'B':
		TOG_BIT(PORTB,pinnumber);
		break;
		case 'C':
		TOG_BIT(PORTC,pinnumber);
		break;
		case 'D':
		TOG_BIT(PORTD,pinnumber);
		break;
		default: break;
	}
}
void set_port_direction(unsigned char portname,unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		DDRA=direction;
		break;
		case 'B':
		DDRB=direction;
		break;
		case 'C':
		DDRC=direction;
		break;
		case 'D':
		DDRD=direction;
		break;
		default: break;
	}
}
void DIO_write_port(unsigned char portname,unsigned char portvalue)
{
	switch(portname)
	{
		case 'A':
		PORTA=portvalue;
		break;
		case 'B':
		PORTB=portvalue;
		break;
		case 'C':
		PORTC=portvalue;
		break;
		case 'D':
		PORTD=portvalue;
		break;
		default: break;
	}
}
unsigned char DIO_read_port(unsigned char portname)
{
	unsigned char return_value;
	switch(portname)
	{
		case 'A':
		return_value=PINA;
		break;
		case 'B':
		return_value=PINB;
		break;
		case 'C':
		return_value=PINC;
		break;
		case 'D':
		return_value=PIND;
		break;
		default: break;
	}
	return return_value;
}
void DIO_vconnectpullup(unsigned char portname,unsigned char pinnumber,unsigned char connect_pullup)
{
  switch(portname)
  {
       case 'A':
       if(connect_pullup==1)
          {
              SET_BIT(PORTA,pinnumber);
          }
       else
         {
              CLR_BIT(PORTA,pinnumber);
         }
     break;
       case 'B':
       if(connect_pullup==1)
       {
	       SET_BIT(PORTB,pinnumber);
       }
       else
       {
	       CLR_BIT(PORTB,pinnumber);
       }
       break;
         case 'c':
         if(connect_pullup==1)
         {
	         SET_BIT(PORTC,pinnumber);
         }
         else
         {
	         CLR_BIT(PORTC,pinnumber);
         }
         break;
           case 'D':
           if(connect_pullup==1)
           {
	           SET_BIT(PORTD,pinnumber);
           }
           else
           {
	           CLR_BIT(PORTD,pinnumber);
           }
           break;
  }
}
void DIO_write_low_nibble(unsigned char portname,unsigned char value)
{
   DIO_write(portname,0,READ_BIT(value,0));
   DIO_write(portname,1,READ_BIT(value,1));
   DIO_write(portname,2,READ_BIT(value,2));
   DIO_write(portname,3,READ_BIT(value,3));
}
void DIO_write_high_nibble(unsigned char portname,unsigned char value)
{
	 DIO_write(portname,4,READ_BIT(value,4));
	 DIO_write(portname,5,READ_BIT(value,5));
	 DIO_write(portname,6,READ_BIT(value,6));
	 DIO_write(portname,7,READ_BIT(value,7));
}