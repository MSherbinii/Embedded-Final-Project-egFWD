#ifndef TIMER_H
#define TIMER_H

#include "../DIO/DIO_Register.h"
#include "STD_types.h"


void TIMER_init(); //initialize Timer0
void TIMER_delay(u16 millisec); //delay of specific amount default uses 256 prescalar
u8 TIMER_getCounterValue(void);


#endif // TIMER_H