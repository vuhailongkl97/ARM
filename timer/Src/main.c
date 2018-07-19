#include "project.h"


char times = 0;

void delay( unsigned int timeout){
	
	unsigned int t1 , t2;
	for( t1 = 0 ; t1 < timeout ; t1 ++)
		for( t2 = 0 ; t2 < 0xFFF ; t2 ++)
			asm(" nop");

}
//clock setup 50mhz for processor
int main(void)
{
	//void system_init( div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb,u32_t div_apb1 , u32_t div_apb2);
	system_init( 8, 100, PLLP_DIV2 , SRC_PLL, AHB_DIV1 ,APB_DIV2  , APB_DIV1);
	rcc_enableclk();
	init_pin();
	timer2_init();
	timer2_start(111);

    while(1)
    {
		#if 0
		led_on(GPIO_BSRR(GPIOD) , GPIO_PIN(13));
		delay(0xFF);
		led_off(GPIO_BSRR(GPIOD) , GPIO_PIN(13));
		delay(0xFF);

		#endif
		

    }

}
