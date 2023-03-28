#include "timer.h"
#include "math.h"
#include "BIT_Math.h"


void TIMER_init(){
	TCCR0 = 0x00; //normal mode
}

void TIMER_delay(u16 millisec){
	u16 Noverflows, TimerInitial;
	double Tmaxdelay, Ttick;
	double Prescaler=256,FCPU=1000;
	u32 overflowCnt = 0;
	
	// Calculate Ttick, Tmaxdelay, and Noverflows based on 256 prescaler
	Ttick = Prescaler / FCPU;      
	Tmaxdelay = 65.56;         
	Noverflows = ceil(millisec / Tmaxdelay);
	
	// Calculate TimerInitial based on remaining time after overflows
	TimerInitial = round((Tmaxdelay - millisec/Noverflows) / Ttick);
	
	// Set initial timer count
	TCNT0 = TimerInitial;
	
	// Start timer with 256 prescaler
	TCCR0 |= (1 << CS02);
	
	// Wait for desired number of overflows
	while (overflowCnt < Noverflows) {
		// Busy wait until overflow flag is set
		while (GET_BIT(TIFR, 0) == 0);
		
		// Clear overflow flag
		SET_BIT(TIFR, 0);
		
		// Increment overflow count
		overflowCnt++;
	}
	
	// Stop timer
	TCCR0 = 0x00;
}
u8 TIMER_getCounterValue(void) {
	return TCNT0;
}