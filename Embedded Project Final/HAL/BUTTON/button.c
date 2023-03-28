#include "button.h"

void BUTTON_Init(u8 BUTTON_u8Port, u8 BUTTON_u8Pin)
{
	DIO_voidSetPinDir(BUTTON_u8Port, BUTTON_u8Pin, DIO_U8_INPUT);
}

u8 BUTTON_Read(u8 BUTTON_u8Port, u8 BUTTON_u8Pin)
{
	u8 BUTTON_Val = DIO_u8GetPinVal(BUTTON_u8Port, BUTTON_u8Pin);
	return BUTTON_Val;
}

