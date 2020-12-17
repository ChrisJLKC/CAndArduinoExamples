#include "LED_Matrix.h"
#include "delay.h"

/*

Example:

init_LED_Matrix(); //-----------------------------------------------------|-----------------------------|
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0, 0, 16, 16, 16, 16, 16, 0, 0, 0);
	delay_blocking(0.001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0, 0, 16, 16, 16, 16, 16, 0, 0, 16);
	delay_blocking(0.001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0, 0, 16, 16, 16, 16, 16, 0, 16, 0);
	delay_blocking(0.001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0, 0, 16, 16, 16, 16, 16, 0, 16, 16);
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

void dis_void(int m1, int m2, int m3, int m4, int m5, int m6, int m7, int m8, int m9, int m10, int m11, int m12, int m13, int m14, int m15, int m16)
{
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m1));
	Pulse_CLK();
	
  LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m2));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m3));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m4));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m5));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m6));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m7));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m8));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m9));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m10));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m11));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m12));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m13));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m14));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m15));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m16));
	Pulse_CLK();
}

void line_void (int m17, int m18, int m19)
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
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m17));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m18));
	Pulse_CLK();
	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+m19));
	Pulse_CLK();
}

void LED_matrix_func(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int n14, int n15, int n16, int n17, int n18, int n19)
{	
	LED_MATRIX_SPICLK_MOSI_PORT->BSRR = (1 << (12+16));

	dis_void(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16);
	line_void(n17, n18, n19);
	delay_blocking(0.0000001);
	LED_MATRIX_IOE_LE_PORT->BSRR = (1 << 6);
	delay_blocking(0.0000001);
	LED_MATRIX_IOE_LE_PORT->BSRR = (1 << (6+16));
}

void CLR_Matrix(void)
{
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 0);
	delay_blocking(0.0001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0, 16);
	delay_blocking(0.0001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 16, 0);
	delay_blocking(0.0001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 16, 16);
	delay_blocking(0.0001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 0);
	delay_blocking(0.0001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0, 16);
	delay_blocking(0.0001);
	LED_matrix_func(16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 0);
	delay_blocking(0.0001);
}

