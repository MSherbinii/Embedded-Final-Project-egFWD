#ifndef LED_H
#define LED_H

#include "STD_Types.h"
#include "DIO_Init.h"

// Car port and pins
#define LED_CAR_PORT DIO_U8_PORTA
#define LED_CAR_R_PIN DIO_U8_PIN0
#define LED_CAR_Y_PIN DIO_U8_PIN1
#define LED_CAR_G_PIN DIO_U8_PIN2

// Pedestrian port and pins
#define LED_PED_PORT DIO_U8_PORTB
#define LED_PED_R_PIN DIO_U8_PIN0
#define LED_PED_Y_PIN DIO_U8_PIN1
#define LED_PED_G_PIN DIO_U8_PIN2

void LED_Init(u8 LED_u8Port, u8 LED_u8Pin);
void LED_ON(u8 LED_u8Port, u8 LED_u8Pin);
void LED_OFF(u8 LED_u8Port, u8 LED_u8Pin);
void LED_TOGGLE(u8 LED_u8Port, u8 LED_u8Pin);




#endif