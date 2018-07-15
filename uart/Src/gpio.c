
#include "project.h"
void init_pin( ){

	unsigned int temp_reg;
  /*Configure GPIO pin : PD12 */
  	temp_reg = read_reg(GPIOD_MODER , ~(3u << 24 ));
	temp_reg |= (GPIO_MODER_OUTPUT << 24);
	write_reg(GPIOD_MODER , temp_reg );
	
}

void led_on(unsigned long addr_BSRR , int number_pin){
	write_reg(addr_BSRR , 1 << number_pin);
}
void led_off(unsigned long addr_BSRR  ,int  number_pin){
	write_reg(	addr_BSRR ,   1 << (number_pin + 16));
}

