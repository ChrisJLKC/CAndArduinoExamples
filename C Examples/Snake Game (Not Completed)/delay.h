#ifndef _DELAY_H_
#define _DELAY_H_

#include "stm32f4xx.h"

void Init_Timer2(void);
void PSC_delay(double TIME_PERIOD);
void delay_blocking(double bdelay);
void delay_blocking_v2(unsigned int us);

#endif
