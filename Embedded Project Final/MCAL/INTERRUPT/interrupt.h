#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../DIO/DIO_Register.h"
#include "math.h"

// Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

// Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

// Rising edge
#define RISING_EDGE_SETUP() MCUCR |= (1 << ISC01) | (1 << ISC00)

// Setup use INT0
#define SETUP_INT0() GICR |= (1 << INT0)

// ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__((signal, used, externally_visible)); \
void INT_VECT(void)

#endif
