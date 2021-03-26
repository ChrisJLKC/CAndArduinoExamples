#include "lcd.h"
#include "delay.h"

void WaitLcdBusy(void)
{
	char port;                // storing variable for Hex number
	 	                  
	set_LCD_bus_input();      // producing an input to the LCD
	set_LCD_RW();             // then allowing the board to write to the LCD
	clr_LCD_RS();             // then we clear the provious write to the LCD
	
	do {
		set_LCD_E();            // Then activating the enable pin to write to the LCD
		delay_blocking_v2(10);        // Giving the LCD time to respond
		port = LCD_PORT->IDR;   // Checking the port specified called port 
		clr_LCD_E();            // Then deactivate the enable pin and clear the response
		delay_blocking_v2(10);        // Giving the LCD time to respond
	}while (port & 0x80);     // checking for the 7th bit 
	
	clr_LCD_RW();             // clearing the writing function 
	set_LCD_bus_output();     // displaying it as an output 
}

void four_bit_mode(unsigned char input) 
{
	unsigned char input_nibble1 = (input & 0xF0);
	unsigned char input_nibble2 = ((input & 0x40) & 0xF0);
	
	LCD_PORT->BSRR = 0x00FF;
	LCD_PORT->BSRR = input_nibble1;
	LCD_strobe();
	
	LCD_PORT->BSRR = 0xFF00;
	LCD_PORT->BSRR = input_nibble2;
	LCD_strobe();
}

void eight_bit_mode(unsigned char d)
{
	LCD_PORT->BSRR=(0xff<<(LCD_D0_pin+16));	//clear data lines
	LCD_PORT->BSRR=(d<<LCD_D0_pin);					//put data on lines
}

void LCD_strobe(void)		//10us high pulse on LCD enable line
{	
	delay_blocking_v2(10);
	set_LCD_E();
	delay_blocking_v2(10);
	clr_LCD_E();
}

void cmdLCD(unsigned char cmd)		//sends a byte to the LCD control register
{
	WaitLcdBusy();				//wait for LCD to be not busy
	clr_LCD_RS();					//control command
	clr_LCD_RW();					//write command
	eight_bit_mode(cmd);		//set data on bus
	LCD_strobe();					//apply command
}

void putLCD(unsigned char put)	//sends a char to the LCD display
{
	WaitLcdBusy();				//wait for LCD to be not busy
	set_LCD_RS();					//text command
	clr_LCD_RW();					//write command
	eight_bit_mode(put);		//set data on bus
	LCD_strobe();					//apply command
}
	
void initLCD(void)
{
		SystemCoreClockUpdate();
		RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;	//enable LCD port clock
	
	
			//CONFIG LCD GPIO PINS
		LCD_PORT->MODER&=~(					//clear pin direction settings
			(3u<<(2*LCD_RS_pin))
			|(3u<<(2*LCD_RW_pin))
			|(3u<<(2*LCD_E_pin))
			|(0xffff<<(2*LCD_D0_pin))
			);
	
	
		LCD_PORT->MODER|=(				//reset pin direction settings to digital outputs
			(1u<<(2*LCD_RS_pin))
			|(1u<<(2*LCD_RW_pin))
			|(1u<<(2*LCD_E_pin))
			|(0x5555<<(2*LCD_D0_pin))
		);

	
			//LCD INIT COMMANDS
	clr_LCD_RS();					//all lines default low
	clr_LCD_RW();
	clr_LCD_E();
	
	delay_blocking_v2(25000);		//25ms startup delay
	cmdLCD(0x38);	//Function set: 2 Line, 8-bit, 5x7 dots
	cmdLCD(0x0c);	//Display on, Cursor blinking command
  cmdLCD(0x01);	//Clear LCD
	cmdLCD(0x06);	//Entry mode, auto increment with no shift
}

void send_char(unsigned char c)
{
	putLCD(c);
}

void send_multi_chars(unsigned char m[])
{
	int i = 0;
	
	do
	{
		send_char(m[i]);
		i++;
	}while (m[i] != 0x00);
}

/*const char Object_table[][6] = {
//	{0x0e,0x0e,0x04,0x04,0x1f,0}, //A, B and C respectively
{0x0e,0x0e,0x15,0x0e,0x04,0},
	{0x00,0x00,0x0a,0x15,0x11,0},
	{0x00,0x00,0x0a,0x1f,0x1f,0}
};

unsigned char Pattern[8] = {
	0x00,
  0x0E,
  0x02,
  0x02,
  0x06,
  0x04,
  0x00,
  0x04
};

void CreateCustomCharacter(unsigned char *Pattern)
{
	int i = 0;
	cmdLCD(0x80);
	for(i=0; i<8; i++)
	{
		cmdLCD(Pattern[i]);
	}
}

void LCDCustom(void) 
{
	CreateCustomCharacter(Pattern);
}

void before_LCD_main(int j)
{
	cmdLCD(0x80);
	
	LCDCustom();
	
	for(j=0; j<8; j++)
	{
		putLCD(j);
	}
} */

void SetCursor(int val)
{
	cmdLCD(val);
}

void CLR_LCD(void)
{
	cmdLCD(0x01);
	cmdLCD(0x80);
}

void main_LCD(unsigned char c[], int inc)
{
	initLCD();
	SetCursor(inc);
	
	send_multi_chars(c);
}
