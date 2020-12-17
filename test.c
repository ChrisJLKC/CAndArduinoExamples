#include "test.h"

#include "ports.h"
#include "delay.h"
#include "strip.h"
#include "led_digits.h"
#include "LED_Matrix.h"
#include "lcd.h"
#include "Game_Menu.h"

#include "PLL_Config.h"

void Init_Com(void)
{
	init_Switches_LEDs_Microphone_and_Buzzer();
	Game_Menu();
}

void Toggle_Com(void)
{
	Game_Menu();
}

void main_Test(void)
{
	PLL_Config();
	SystemCoreClockUpdate();
	Init_Com();
	Init_Timer2();

	while(1)
	{
		
	}
}

void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~TIM_SR_UIF;
	Toggle_Com();
}
