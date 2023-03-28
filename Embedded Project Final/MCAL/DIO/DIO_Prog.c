#include "STD_types.h"
#include "BIT_math.h"
#include "DIO_init.h"
#include "DIO_Register.h"

void DIO_voidSetPinDir(u8 Copy_u8Port,u8 Copy_u8Pin , u8 Copy_u8Dir)
{
	
	switch(Copy_u8Port)
	{
		
		case DIO_U8_PORTA :
		if( Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRA,Copy_u8Pin);
		}
		else if ( Copy_u8Dir ==DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRA,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTB :
		if( Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRB,Copy_u8Pin);
		}
		else if ( Copy_u8Dir ==DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRB,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTC :
		if( Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRC,Copy_u8Pin);
		}
		else if ( Copy_u8Dir ==DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRC,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTD :
		if( Copy_u8Dir == DIO_U8_OUTPUT)
		{
			SET_BIT(DDRD,Copy_u8Pin);
		}
		else if ( Copy_u8Dir ==DIO_U8_INPUT)
		{
			CLEAR_BIT(DDRD,Copy_u8Pin);
		}
		break;
		
	}
}

void DIO_voidSetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin , u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		
		case DIO_U8_PORTA :
		if( Copy_u8Val == DIO_U8_HIGH )
		{
			SET_BIT(PORTA,Copy_u8Pin);
		}
		else if ( Copy_u8Val ==DIO_U8_LOW )
		{
			CLEAR_BIT(PORTA,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTB :
		if( Copy_u8Val == DIO_U8_HIGH )
		{
			SET_BIT(PORTB,Copy_u8Pin);
		}
		else if ( Copy_u8Val ==DIO_U8_LOW )
		{
			CLEAR_BIT(PORTB,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTC :
		if( Copy_u8Val == DIO_U8_HIGH )
		{
			SET_BIT(PORTC,Copy_u8Pin);
		}
		else if ( Copy_u8Val ==DIO_U8_LOW )
		{
			CLEAR_BIT(PORTC,Copy_u8Pin);
		}
		break;
		
		case DIO_U8_PORTD :
		if( Copy_u8Val == DIO_U8_HIGH )
		{
			SET_BIT(PORTD,Copy_u8Pin);
		}
		else if ( Copy_u8Val ==DIO_U8_LOW )
		{
			CLEAR_BIT(PORTD,Copy_u8Pin);
		}
		break;
		
	}
	
}

void DIO_voidSetPortVal(u8 Copy_u8Port, u8 Copy_u8Val)
{
	switch(Copy_u8Port)
	{
		
		case DIO_U8_PORTA :
		PORTA = Copy_u8Val;
		break;
		
		case DIO_U8_PORTB :
		PORTB = Copy_u8Val;
		break;
		
		case DIO_U8_PORTC :
		PORTC = Copy_u8Val;
		break;
		
		case DIO_U8_PORTD :
		PORTD = Copy_u8Val;
		break;
		
	}
	
}

void DIO_voidTogglePinVal(u8 Copy_u8Port, u8 Copy_u8Pin)
{
	switch(Copy_u8Port){
		case DIO_U8_PORTA:
		//PORTA ^= (1<<pinNumber);
		TOGGLE_BIT(PORTA,Copy_u8Pin);
		break;
		case DIO_U8_PORTB:
		//PORTB ^= (1<<pinNumber);
		TOGGLE_BIT(PORTB,Copy_u8Pin);
		break;
		case DIO_U8_PORTC:
		//PORTC ^= (1<<pinNumber);
		TOGGLE_BIT(PORTC,Copy_u8Pin);
		break;
		case DIO_U8_PORTD:
		//PORTD ^= (1<<pinNumber);
		TOGGLE_BIT(PORTD,Copy_u8Pin);
		break;
	}
}

u8 DIO_u8GetPinVal(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8Value = 0;
	switch(Copy_u8Port)
	{
		case DIO_U8_PORTA :
		Local_u8Value= GET_BIT(PINA,Copy_u8Pin);
		break;
		
		case DIO_U8_PORTB:
		Local_u8Value= GET_BIT(PINB,Copy_u8Pin);
		break;
		
		case DIO_U8_PORTC :
		Local_u8Value= GET_BIT(PINC,Copy_u8Pin);
		break;
		
		case DIO_U8_PORTD :
		Local_u8Value= GET_BIT(PIND,Copy_u8Pin);
		break;
	}
	
	return Local_u8Value;
	
}
