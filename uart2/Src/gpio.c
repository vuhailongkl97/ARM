
#include "project.h"

void init_pin(){

	unsigned int temp_reg;
  /*Configure GPIO pin : PD12 13 14 15  */
  	temp_reg = read_reg(GPIO_MODER(GPIOD) , ~(0xFF << 24 ));
	temp_reg |= ( (GPIO_MODER_OUTPUT << 24) |(GPIO_MODER_OUTPUT << 26) |(GPIO_MODER_OUTPUT << 28) \
	 | (GPIO_MODER_OUTPUT << 30)) ;
	write_reg(GPIO_MODER(GPIOD) , temp_reg );
	
	
	
	// output push-pull , open-drain
  	temp_reg = read_reg(GPIO_OTYPER(GPIOD) , ~(0xF << 12 ));
	temp_reg |= ( (PUSH_PULL << 12) |(PUSH_PULL << 13) |(PUSH_PULL << 14) \
	 | (PUSH_PULL << 15)) ;
	write_reg(GPIO_OTYPER(GPIOD) , temp_reg );	
	
	
	// output no pull-up pull-down 
	
	temp_reg = read_reg(GPIO_PUPDR(GPIOD) , ~(0xFF<< 24));
	temp_reg |= ( (NO_PULL << 24) |(NO_PULL << 26) |(NO_PULL << 28) \
	 | (NO_PULL << 30)) ;
	write_reg(GPIO_PUPDR(GPIOD) , temp_reg );
	
	// high speed
	
	temp_reg = read_reg(GPIO_OSPEEDR(GPIOD) , ~(0xFF<< 24));
	temp_reg |= ( (HIGH_SPEED << 24) |(HIGH_SPEED << 26) |(HIGH_SPEED << 28) \
	 | (HIGH_SPEED << 30)) ;
	write_reg(GPIO_OSPEEDR(GPIOD) , temp_reg );
	
	
	
	
}

void led_on(unsigned long mPORT , unsigned int pin){
	write_reg(  GPIO_BSRR(mPORT) ,  pin);
}
void led_off(unsigned long mPORT  ,unsigned int  pin){
	write_reg(	GPIO_BSRR(mPORT) ,   pin << 16);
}
void GPIO_TongglePin( unsigned long mPORT , unsigned int pin){
	// temp_reg1 get bit[8:0]; temp_reg2 get bit[15:8] of ODR
	unsigned int temp_reg1 = read_reg(GPIO_ODR(mPORT) , ~(0xFFu));
	unsigned int temp_reg2 = read_reg(GPIO_ODR(mPORT) , ~(0xFF00u));
	
	temp_reg1 = (temp_reg2 << 16) | temp_reg1;
	temp_reg1 = ~temp_reg1;
	write_reg(GPIO_BSRR(mPORT) , temp_reg1);
	
}


