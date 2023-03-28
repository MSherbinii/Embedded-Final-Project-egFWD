#include "app.h"

#define NORMAL_MODE 0
#define PEDESTRIAN_MODE 1
#define LONG_PRESS_THRESHOLD 750 // 750ms

u8 mode = NORMAL_MODE;
u8 curr_car_LED = 0;
u8 curr_ped_LED = 0;
u8 i;
u8 button_press_count = 0;
u16 button_press_time = 0;


void APP_init(void){
	
	//Car LED initialization
	LED_Init(LED_CAR_PORT,LED_CAR_G_PIN);
	LED_Init(LED_CAR_PORT,LED_CAR_Y_PIN);
	LED_Init(LED_CAR_PORT,LED_CAR_R_PIN);
	
	//Pedestrian LED initialization
	LED_Init(LED_PED_PORT,LED_PED_G_PIN);
	LED_Init(LED_PED_PORT,LED_PED_Y_PIN);
	LED_Init(LED_PED_PORT,LED_PED_R_PIN);
	
	//BUTTON initialization
	BUTTON_Init(BUTTON_PORT,BUTTON_PIN);
	
	//TIMER initialization
	TIMER_init();
	
	
	//Enable Global interrupts & setup rising edge detection for button
	sei();
	RISING_EDGE_SETUP();
	SETUP_INT0();
}
void APP_start(void)
{
	if (mode==NORMAL_MODE)
	{
		LED_ON(LED_PED_PORT,LED_PED_R_PIN);
		switch (curr_car_LED)
		{
			case 0:
				LED_ON(LED_CAR_PORT,LED_CAR_R_PIN);
				LED_OFF(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_OFF(LED_CAR_PORT,LED_CAR_G_PIN);
				for (i=0; i<25; i++)
				{
					TIMER_delay(190);
					if (mode==PEDESTRIAN_MODE)
					{
						LED_OFF(LED_CAR_PORT,LED_CAR_R_PIN);
						LED_OFF(LED_PED_PORT,LED_PED_R_PIN);
						curr_ped_LED=2;
						break;
					}
				}
				curr_car_LED=2;
				break;
			case 1:
				LED_OFF(LED_CAR_PORT,LED_CAR_R_PIN);
				LED_OFF(LED_CAR_PORT,LED_CAR_G_PIN);
				for (i=0; i<10; i++)
				{
					LED_ON(LED_CAR_PORT,LED_CAR_Y_PIN);
					TIMER_delay(220);
					LED_OFF(LED_CAR_PORT,LED_CAR_Y_PIN);
					TIMER_delay(220);
					if (mode==PEDESTRIAN_MODE)
					{
						LED_OFF(LED_CAR_PORT,LED_CAR_Y_PIN);
						LED_OFF(LED_PED_PORT,LED_PED_R_PIN);
						curr_ped_LED=1;
						break;
						
					}
				}
				curr_car_LED=0;
				break;
			case 2:
				LED_ON(LED_CAR_PORT,LED_CAR_G_PIN);
				LED_OFF(LED_CAR_PORT,LED_CAR_Y_PIN);
				LED_OFF(LED_CAR_PORT,LED_CAR_R_PIN);
              	for (i=0; i<25; i++)
              	{
	              	TIMER_delay(190);
	              	if (mode==PEDESTRIAN_MODE)
	              	{
						LED_OFF(LED_CAR_PORT,LED_CAR_G_PIN);
						LED_OFF(LED_PED_PORT,LED_PED_R_PIN);
						curr_ped_LED=1;
		              	break;
	              	}
              	}
				curr_car_LED=1;
			    break;
		}
	}
		else
		{
			
			for (u8 y=0; y<6; y++)
			{
				switch(curr_ped_LED)
				{
					case 0:
						LED_ON(LED_PED_PORT,LED_PED_R_PIN);
						LED_ON(LED_CAR_PORT,LED_CAR_G_PIN);
						TIMER_delay(5000);
						LED_OFF(LED_PED_PORT,LED_PED_R_PIN);
						LED_OFF(LED_CAR_PORT,LED_CAR_G_PIN);
						curr_ped_LED=2;
						break;
					case 1:
						for (i=0; i<10; i++)
						{
							LED_ON(LED_CAR_PORT,LED_CAR_Y_PIN);
							LED_ON(LED_PED_PORT,LED_PED_Y_PIN);
							TIMER_delay(220);
							LED_OFF(LED_CAR_PORT,LED_CAR_Y_PIN);
							LED_OFF(LED_PED_PORT,LED_PED_Y_PIN);
							TIMER_delay(220);	
						}
						curr_ped_LED=0;
						break;
					case 2:
						LED_ON(LED_PED_PORT,LED_PED_G_PIN);
						LED_ON(LED_CAR_PORT,LED_CAR_R_PIN);
						TIMER_delay(5000);
						LED_OFF(LED_CAR_PORT,LED_CAR_R_PIN);
						LED_OFF(LED_PED_PORT,LED_PED_G_PIN);
						curr_ped_LED=1;
						break;
				}
			}
			mode=NORMAL_MODE;
			
		}
}



// Interrupt used to switch to Pedestrian Mode and handle button press logic
ISR(EXT_INT_0)
{
	button_press_count++;
	if (button_press_count == 1)
	{
		button_press_time = TIMER_getCounterValue();
	}
	if (button_press_count >= 2)
	{
		if (TIMER_getCounterValue() - button_press_time < LONG_PRESS_THRESHOLD)
		{
			button_press_count = 0;
			return;
		}
		else
		{
			button_press_count = 1;
			button_press_time = TIMER_getCounterValue();
		}
	}
	if (curr_car_LED == 0 || curr_car_LED == 1)
	{
		if (mode != PEDESTRIAN_MODE)
		{
			mode = PEDESTRIAN_MODE;
		}
	}
}