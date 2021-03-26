#include "LED_Matrix.h"
#include "delay.h"

/*
The Matrix consists of 8 lines of 16 LEDs. Only one line of leds can only be controlled at once. So if we falsh over then quick enough, it percieves that it is a display with the object.
The use of a map layout is delibrate so we can visually see what we implementing when we detail when something is on or off. It shows this in the Game Menu in more detail.
*/

#define LED_MATRIX_IOE_LE_PORT GPIOB
#define LED_MATRIX_SPICLK_MOSI_PORT GPIOC 

void init_LED_Matrix(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	
	LED_MATRIX_IOE_LE_PORT->OTYPER |= (0 << 6)|(0 << 12);
	
	LED_MATRIX_IOE_LE_PORT->MODER |=  (1u << (6*2))|(1u << (12*2));
	LED_MATRIX_IOE_LE_PORT->MODER &= ~((2u << (6*2))|(2u << (12*2)));
	
	LED_MATRIX_SPICLK_MOSI_PORT->OTYPER |= (0 << 10)|(0 << 12);
	
	LED_MATRIX_SPICLK_MOSI_PORT->MODER |=  (1u << (10*2))|(1u << (12*2));
	LED_MATRIX_SPICLK_MOSI_PORT->MODER &= ~((2u << (10*2))|(2u << (12*2)));
	
	LED_MATRIX_IOE_LE_PORT->BSRR = (1 << (12+16));
}

void Pulse_CLK(void) 
{
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << 10);
	delay_blocking(0.000001);
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (10+16));
	delay_blocking(0.000001);
}

int on_or_off(int value)
{
	int output_leds = 0;
	
	switch(value) {
		case 0:
			output_leds |= LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
			break;
		
		case 1:
			output_leds |= LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << 12);
			break;
		
		default:
			output_leds |= LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
	}
	
	return output_leds;
}

void dis_void(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int m9, int m10, int m11, int m12, int m13, int m14, int m15, int m16)
{
	on_or_off(m1);
	Pulse_CLK();
	
	on_or_off(m2);
	Pulse_CLK();
	
	on_or_off(m3);
	Pulse_CLK();
	
	on_or_off(m4);
	Pulse_CLK();
	
	on_or_off(m5);
	Pulse_CLK();
	
	on_or_off(m6);
	Pulse_CLK();

	on_or_off(m7);
	Pulse_CLK();
	
	on_or_off(m8);
	Pulse_CLK();
	
	on_or_off(m9);
	Pulse_CLK();
	
	on_or_off(m10);
	Pulse_CLK();
	
  on_or_off(m11);
	Pulse_CLK();
	
	on_or_off(m12);
	Pulse_CLK();
	
	on_or_off(m13);
	Pulse_CLK();
	
	on_or_off(m14);
	Pulse_CLK();
	
	on_or_off(m15);
	Pulse_CLK();
	
	on_or_off(m16);
	Pulse_CLK();
}

void line_void(int m17, int m18, int m19)
{
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));
	Pulse_CLK();
	
	on_or_off(m17);
	Pulse_CLK();
	
	on_or_off(m18);
	Pulse_CLK();
	
	on_or_off(m19);
	Pulse_CLK();
}

void LED_matrix_config_line(int line_level_part_1, int line_level_part_2, int line_level_part_3)
{
	line_void(line_level_part_1, line_level_part_2, line_level_part_3);
}

void LED_matrix_led_func(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14, int n15, int n16)
{	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));

	dis_void(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16);
}

void push_data(void)
{
	delay_blocking(0.0000001);
	LED_MATRIX_IOE_LE_PORT->BSRR = (1 << 6);
	delay_blocking(0.0000001);
	LED_MATRIX_IOE_LE_PORT->BSRR = (1 << (6+16));
}

void line_and_push(int line_level_part_01, int line_level_part_02, int line_level_part_03)
{
	LED_matrix_config_line(line_level_part_01, line_level_part_02, line_level_part_03);
	push_data();
}

void CLR_Matrix(void)
{
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.0001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.0001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.0001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.0001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.0001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.0001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.0001);
}

