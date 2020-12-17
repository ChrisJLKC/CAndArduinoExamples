#include "led_digits.h"
#include "delay.h"

#include "stm32f4xx.h"

#define LED_PP_LED_DIGITS_PORT GPIOE

void init_Led_Digits(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	
	LED_PP_LED_DIGITS_PORT->OTYPER |= (0 << 2)|(0 << 3)|(0 << 4)|(0 << 5)|(0 << 6)|(0 << 7)|(0 << 8)|(0 << 9);
	
	LED_PP_LED_DIGITS_PORT->MODER |=  (1u << (2*2))|(1u << (3*2))|(1u << (4*2))|(1u << (5*2))|(1u << (6*2))|(1u << (7*2))|(1u << (8*2))|(1u << (9*2));
	LED_PP_LED_DIGITS_PORT->MODER &= ~((2u << (2*2))|(2u << (3*2))|(2u << (4*2))|(2u << (5*2))|(2u << (6*2))|(2u << (7*2))|(2u << (8*2))|(2u << (9*2)));
	
	LED_PP_LED_DIGITS_PORT->OTYPER |= (0 << 10)|(0 << 11);
	
	LED_PP_LED_DIGITS_PORT->MODER |= (1u << (10*2))|(1u << (11*2));
	LED_PP_LED_DIGITS_PORT->MODER &= ~((2u << (10*2))|(2u << (11*2)));
	
	LED_PP_LED_DIGITS_PORT->OTYPER |= (0 << 15);
	
	LED_PP_LED_DIGITS_PORT->MODER |= (1u << (15*2));
	LED_PP_LED_DIGITS_PORT->MODER &= ~(2u << (15*2));
	
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (15+16));	
}

int Led_Digit_Selec(int n)
{
	int output_digit_led = 0;
	switch(n) {		
		case 0:
						output_digit_led |= (1 << 2)|(1 << 6)|(1 << 7)|(1 << 8)|(1 << 5)|(1 << 3);
						break;
		
		case 1:
						output_digit_led |= (1 << 2)|(1 << 3);
						break;
		
		case 2:
						output_digit_led |= (1 << 6)|(1 << 7)|(1 << 4)|(1 << 3)|(1 << 5);
						break;
		
		case 3:
						output_digit_led |= (1 << 6)|(1 << 7)|(1 << 4)|(1 << 8)|(1 << 5);
						break;
		
		case 4:
						output_digit_led |= (1 << 2)|(1 << 4)|(1 << 7)|(1 << 8);
						break;
		
		case 5:
						output_digit_led |= (1 << 6)|(1 << 2)|(1 << 4)|(1 << 8)|(1 << 5);
						break;
		
		case 6:
						output_digit_led |= (1 << 6)|(1 << 2)|(1 << 4)|(1 << 8)|(1 << 5)|(1 << 3);
						break;
		
		case 7:
						output_digit_led |= (1 << 6)|(1 << 7)|(1 << 8);
						break;
		
		case 8:
						output_digit_led |= (1 << 6)|(1 << 7)|(1 << 8)|(1 << 5)|(1 << 3)|(1 << 4)|(1 << 2);
						break;
		
		case 9: 
						output_digit_led |= (1 << 6)|(1 << 2)|(1 << 4)|(1 << 7)|(1 << 8)|(1 << 5);
						break;
		
		case 10:
						output_digit_led |= (1 << 6)|(1 << 2)|(1 << 3)|(1 << 5)|(1 << 8);
						break;
		
		case 11:
						output_digit_led |= (1 << 2)|(1 << 3)|(1 << 4)|(1 << 7)|(1 << 8);
						break;
		
		case 12:
						output_digit_led |= (1 << 7)|(1 << 8);
						break;
		
		default:
						output_digit_led = 0x3FC0000;
	}	
	
	return output_digit_led;
}


void FIRST_LED_DIGIT(int first_digit)
{
	LED_PP_LED_DIGITS_PORT->BSRR = 0x3FC0000;
	LED_PP_LED_DIGITS_PORT->BSRR = Led_Digit_Selec(first_digit);
	delay_blocking(0.0000001);
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (10));
	delay_blocking(0.0000001);
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (11+16));
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (10+16));
}

void SECOND_LED_DIGIT(int second_digit)
{
	LED_PP_LED_DIGITS_PORT->BSRR = 0x3FC0000;
	LED_PP_LED_DIGITS_PORT->BSRR = Led_Digit_Selec(second_digit);
	delay_blocking(0.0000001);
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (11));
	delay_blocking(0.0000001);
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (10+16));
	LED_PP_LED_DIGITS_PORT->BSRR = (1 << (11+16));
}


void Set_Led_Digit(int section, int digit)
{
	switch(section) {
		case 1:
			FIRST_LED_DIGIT(digit);
			break;
		
		case 2:
			SECOND_LED_DIGIT(digit);
			break;
	}		
}
