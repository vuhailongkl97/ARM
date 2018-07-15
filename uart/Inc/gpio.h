#ifndef __GPIO_H__
#define __GPIO_H__

void led_on(unsigned long addr_BSRR , int number_pin);
void delay(unsigned int );	
void led_off(unsigned long addr_BSRR , int number_pin);
void init_pin( );

#endif
