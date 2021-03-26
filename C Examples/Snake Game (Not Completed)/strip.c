#include "strip.h"
#include "delay.h"

#include "stm32f4xx.h"

#define LED_PP_RGB_STRIP_PORT GPIOE

void init_RGBStrip(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	
	LED_PP_RGB_STRIP_PORT->OTYPER |= (0 << 2)|(0 << 3)|(0 << 4)|(0 << 5)|(0 << 6)|(0 << 7)|(0 << 8)|(0 << 9);
	
	LED_PP_RGB_STRIP_PORT->MODER |=  (1u << (2*2))|(1u << (3*2))|(1u << (4*2))|(1u << (5*2))|(1u << (6*2))|(1u << (7*2))|(1u << (8*2))|(1u << (9*2));
	LED_PP_RGB_STRIP_PORT->MODER &= ~((2u << (2*2))|(2u << (3*2))|(2u << (4*2))|(2u << (5*2))|(2u << (6*2))|(2u << (7*2))|(2u << (8*2))|(2u << (9*2)));
	
	LED_PP_RGB_STRIP_PORT->OTYPER |= (0 << 12)|(0 << 13)|(0 << 14);
	
	LED_PP_RGB_STRIP_PORT->MODER |= (1u << (12*2))|(1u << (13*2))|(1u << (14*2));
	LED_PP_RGB_STRIP_PORT->MODER &= ~((2u << (12*2))|(2u << (13*2))|(2u << (14*2)));
	
	LED_PP_RGB_STRIP_PORT->OTYPER |= (0 << 0);
	
	LED_PP_RGB_STRIP_PORT->MODER |= (1u << (0*2));
	LED_PP_RGB_STRIP_PORT->MODER &= ~(2u << (0*2));
	
	LED_PP_RGB_STRIP_PORT->BSRR = 1 << (0+16);
	
}

int Led_Selec(int n)
{
	int output_led = 0;
	switch(n) {		
		case 0:
						output_led |= (1 << 2);
						break;
		
		case 1:
						output_led |= (1 << 3);
						break;
		
		case 2:
						output_led |= (1 << 4);
						break;
		
		case 3:
						output_led |= (1 << 5);
						break;
		
		case 4:
						output_led |= (1 << 6);
						break;
		
		case 5:
						output_led |= (1 << 7);
						break;
		
		case 6:
						output_led |= (1 << 8);
						break;
		
		case 7:
						output_led |= (1 << 9);
						break;
		
		default:
						output_led = 0x3FC0000;
	}	
	
	return output_led;
}


void Update_RGB_strip_Group_Red(int red)
{
	LED_PP_RGB_STRIP_PORT->BSRR = 0x3FC0000;
	LED_PP_RGB_STRIP_PORT->BSRR = Led_Selec(red);
	delay_blocking(0.0000001);
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (12));
	delay_blocking(0.0000001);
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (13+16));
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (14+16));
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (12+16));
}

void Update_RGB_strip_Group_Green(int green)
{
	LED_PP_RGB_STRIP_PORT->BSRR = 0x3FC0000;
	LED_PP_RGB_STRIP_PORT->BSRR = Led_Selec(green);
	delay_blocking(0.0000001);
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (13));
	delay_blocking(0.0000001);
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (12+16));
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (14+16));
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (13+16));
}

void Update_RGB_strip_Group_Blue(int blue)
{
	LED_PP_RGB_STRIP_PORT->BSRR = 0x3FC0000;
	LED_PP_RGB_STRIP_PORT->BSRR = Led_Selec(blue);
	delay_blocking(0.0000001);
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (14));
	delay_blocking(0.0000001);
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (12+16));
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (13+16));
	LED_PP_RGB_STRIP_PORT->BSRR = (1 << (14+16));
}

void Set_RGB_func(int group, int led)
{
	switch(group) {
		case 1:
			Update_RGB_strip_Group_Red(led);
			break;
		
		case 2:
			Update_RGB_strip_Group_Green(led);
			break;
		
		case 3:
			Update_RGB_strip_Group_Blue(led);
			break;
	}		
}
