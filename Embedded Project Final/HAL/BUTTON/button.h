#ifndef BUTTON_H
#define BUTTON_H

#include "STD_Types.h"
#include "DIO_Init.h"

#define BUTTON_PORT DIO_U8_PORTD
#define BUTTON_PIN DIO_U8_PIN2

void BUTTON_Init(u8 BUTTON_u8Port, u8 BUTTON_u8Pin);
u8 BUTTON_Read(u8 BUTTON_u8Port, u8 BUTTON_u8Pin);


#endif