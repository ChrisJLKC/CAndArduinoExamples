#include "delay.h" 

void Init_Timer2()
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->DIER |= TIM_DIER_UIE;

	TIM2->PSC = 256-1;
	TIM2->ARR = 35156;
	TIM2->CNT = 0;
	NVIC->ISER[0] |= (1u << 28);
	TIM2->CR1 |= TIM_CR1_CEN;
}

void delay_blocking(double bdelay)
{
	unsigned int i;
	double blocking_delay = 18 / bdelay;
	for(i=0; i<SystemCoreClock/blocking_delay; i++);
}
	
void delay_blocking_v2(unsigned int us)
{
	unsigned char i;
	while(us--)
	{
		for(i=0; i<SystemCoreClock/4000000; i++){__NOP();}
	}
}

