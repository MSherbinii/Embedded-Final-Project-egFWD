#ifndef DIO_REGISTER_H
#define DIO_REGISTER_H

#include "STD_types.h"

//DIO Registers
#define DDRA    (*((volatile u8 *)0x3A))
#define DDRB    (*((volatile u8 *)0x37))
#define DDRC    (*((volatile u8 *)0x34))
#define DDRD    (*((volatile u8 *)0x31))

#define PORTA   (*((volatile u8 *)0x3B))
#define PORTB   (*((volatile u8 *)0x38))
#define PORTC   (*((volatile u8 *)0x35))
#define PORTD   (*((volatile u8 *)0x32))

#define PINA    (*((volatile u8 *)0x39))
#define PINB    (*((volatile u8 *)0x36))
#define PINC    (*((volatile u8 *)0x33))
#define PIND    (*((volatile u8 *)0x30))

//Timer Registers
#define TCCR0 (*(volatile u8 *)(0x53))
#define TCNT0 (*(volatile u8 *)(0x52))
#define TIFR (*(volatile u8 *)(0x58))
#define TIMSK (*(volatile u8 *)(0x59))
// Define bits
#define CS02 2
#define TOIE0 0
#define TOV0 0


//Interrupts Registers
#define SREG (*(volatile u8 *)(0x5F))
#define GICR (*(volatile u8 *)(0x5B))
#define MCUCR (*(volatile u8 *)(0x55))
// Define Bits
#define ISC00   0
#define ISC01   1
#define INT0    6

#endif

