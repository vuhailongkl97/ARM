
#include "main.h"

void init_pin(){
	unsigned int temp_reg;
	temp_reg = read_reg(GPIOD_MODER , ~(0x03<<28));
	temp_reg  = temp_reg | (GPIO_MODER_OUTPUT << 28 );
	//set mode  pd12
	write_reg(GPIOD_MODER , temp_reg );
	
}
void led_on(unsigned char number_pin){
	write_reg(GPIOD_BSRR , 1 << number_pin);
}
void led_off(unsigned char number_pin){
	write_reg(	GPIOD_BSRR ,   1 << (number_pin + 16));

}

void delay( unsigned int timeout){
	
	unsigned int t1 , t2;
	for( t1 = 0 ; t1 < timeout ; t1 ++)
		for( t2 = 0 ; t2 < 0xFFF ; t2 ++)
			asm(" nop");

}
void rcc_enableclk(){
	unsigned int temp_reg;
	temp_reg = read_reg(RCC_AHB1ENR , ~(1 <<3));
	temp_reg  = temp_reg | (1 << 3 );
	write_reg(RCC_AHB1ENR , temp_reg );

}
int main(void)
{

  rcc_enableclk();
  init_pin();

  while (1)
  {
	  led_on(led);
	  delay(200);
	  led_off(led);
	  delay(200);

  }
}
