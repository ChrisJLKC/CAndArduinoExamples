#include "Game_Menu.h"
#include "delay.h"
#include "LED_Matrix.h"
#include "lcd.h"
#include "led_digits.h"
#include "strip.h"
#include "delay.h"
#include "ports.h"

#define USER_BUTTON_NOT_PRESSED 0x00
#define USER_BUTTON_PRESSED 0x01

#define USER_BUTTON_GPIO GPIOA
#define BUZZER_GPIO      GPIOB
#define EXT_BUTTONS_GPIO GPIOG
#define EXT_MIC_GPIO     GPIOA


void init_Switches_LEDs_Microphone_and_Buzzer(void)
{
	USER_BUTTON_GPIO->MODER |= (0 << (0*2));
	
	EXT_BUTTONS_GPIO->OTYPER |= (0 << 0)|(0 << 1)|(0 << 2)|(0 << 3);
	EXT_BUTTONS_GPIO->MODER |= (0 << (0*2))|(0 << (1*2))|(0 << (2*2))|(0 << (3*2));
	
	BUZZER_GPIO->OTYPER |= (0 << 13);
	BUZZER_GPIO->MODER |= (1u << (13*2));
	BUZZER_GPIO->MODER &= ~(2u << (13*2));
	
	EXT_MIC_GPIO->OTYPER |= (0 << 3);
	EXT_MIC_GPIO->OTYPER |= (0 << (3*2));
	
	NUC_LEDS_INIT_DEC();
	NUC_LEDS_INIT_PROOF();
	
	EXT_LEDS_INIT_PP();
	EXT_LEDS_INIT_PP_RED_DEC();
	EXT_LEDS_INIT_PP_RED_PROOF();
	EXT_LEDS_INIT_PP_YELLOW_DEC();
	EXT_LEDS_INIT_PP_YELLOW_PROOF();
	EXT_LEDS_INIT_PP_GREEN_DEC();
	EXT_LEDS_INIT_PP_GREEN_PROOF();
	
	EXT_LEDS_INIT_OD_PORTF();
	EXT_LEDS_INIT_OD_DEC_WHITE_PORTF();
	EXT_LEDS_INIT_OD_PROOF_WHITE_PORTF();
	EXT_LEDS_INIT_OD_PORTC();
	EXT_LEDS_INIT_OD_DEC_RED_PORTC();
	EXT_LEDS_INIT_OD_PROOF_RED_PORTC();
	EXT_LEDS_INIT_OD_DEC_YELLOW_PORTC();
	EXT_LEDS_INIT_OD_PROOF_YELLOW_PORTC();
	EXT_LEDS_INIT_OD_DEC_GREEN_PORTC();
	EXT_LEDS_INIT_OD_PROOF_GREEN_PORTC();
	
	initLCD();
	init_Led_Digits();
	init_LED_Matrix();
	init_RGBStrip();
}

void Game_Menu(void)
{
	// For Matrix, 0 is resetting the LED and 1 is for the LED to be on.
	// For example:
	// LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	// line_and_push(1, 1, 1); This is location of the line is in binary, so detailing this is the 8th line due to 0 being a line 
	// By the way, everything is written backwards, updates will fix this
	
	main_LCD("Welcome to Snake", 0x80);
	
	Set_Led_Digit(1, 11);
	delay_blocking(0.01);
	Set_Led_Digit(2, 12);
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 0);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 1);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 2);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);

	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 3);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 4);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 5);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 6);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 7);
	Set_RGB_func(2, 8);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(1, 8);
	Set_RGB_func(2, 0);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 1);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 2);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 3);
	Set_RGB_func(3, 8);

	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 4);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 5);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 6);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 7);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 0);
	Set_RGB_func(2, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 1);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 2);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 3);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 4);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 5);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 6);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 7);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 6);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 5);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 4);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 3);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 2);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 1);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(3, 0);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 7);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 6);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 5);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 4);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 3);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 2);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 1);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	
	delay_blocking(0.01);
	
	LED_matrix_led_func(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	line_and_push(1, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1);
	line_and_push(1, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0);
	line_and_push(1, 0, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 1);
	delay_blocking(0.001);
	LED_matrix_led_func(0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0);
	line_and_push(0, 1, 0);
	delay_blocking(0.001);
	LED_matrix_led_func(1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1);
	line_and_push(0, 0, 1);
	delay_blocking(0.001);
	
	delay_blocking(0.01);
	
	Set_RGB_func(2, 0);
	Set_RGB_func(3, 8);
	
	CLR_Matrix();
	

}
