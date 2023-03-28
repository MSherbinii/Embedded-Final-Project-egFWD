#include "led.h"

void LED_Init(u8 LED_u8Port, u8 LED_u8Pin)
{
	DIO_voidSetPinDir(LED_u8Port,LED_u8Pin, DIO_U8_OUTPUT);
}

void LED_ON(u8 LED_u8Port, u8 LED_u8Pin)
{
	DIO_voidSetPinVal(LED_u8Port,LED_u8Pin, DIO_U8_HIGH);
}

void LED_OFF(u8 LED_u8Port, u8 LED_u8Pin)
{
	DIO_voidSetPinVal(LED_u8Port,LED_u8Pin, DIO_U8_LOW);
}

void LED_TOGGLE(u8 LED_u8Port, u8 LED_u8Pin)
{
	DIO_voidTogglePinVal(LED_u8Port, LED_u8Pin);
}