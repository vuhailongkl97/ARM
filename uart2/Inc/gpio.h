#ifndef __GPIO_H__
#define __GPIO_H__

void led_on(unsigned long mPORT ,unsigned int pin);
void led_off(unsigned long mPORT ,unsigned int pin);
void GPIO_TongglePin(unsigned long mPORT, unsigned int pin);
void init_pin( );
void delay (unsigned int );	

#endif
