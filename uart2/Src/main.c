#include "project.h"


char times = 0;

void delay( u32_t timeout){
	
	u32_t t1 , t2;
	for( t1 = 0 ; t1 < timeout ; t1 ++)
		for( t2 = 0 ; t2 < 0xFFF ; t2 ++)
			asm(" nop");

}
//clock setup 50mhz for processor
int main(void)
{
	//void system_init( div_m, u32_t mul_n, u32_t div_p, u32_t system_source,u32_t div_ahb,u32_t div_apb1 , u32_t div_apb2);
	system_init( 8, 100, PLLP_DIV2 , SRC_PLL, AHB_DIV1 ,APB_DIV8  , APB_DIV1);
	rcc_enableclk();
	init_pin();
	
	uart_init(100, 16 , 9600);
	init_interrupt();
	usart_send_string("Hello world -VHL");
	

    while(1)
    {
	#if 1
        if (0 != rx_data)
        {
            usart_send_byte(rx_data);
			GPIO_TongglePin(GPIOD , (GPIO_PIN(12) | GPIO_PIN(13) | GPIO_PIN(14) | GPIO_PIN(15) ) ) ;
		
            rx_data = 0;
        }
	
    #endif

		

    }

}
