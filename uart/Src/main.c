#include "project.h"

char times = 0;

void delay( unsigned int timeout){
	
	unsigned int t1 , t2;
	for( t1 = 0 ; t1 < timeout ; t1 ++)
		for( t2 = 0 ; t2 < 0xFFF ; t2 ++)
			asm(" nop");

}
int main(void)
{
	system_init();
	rcc_enableclk();
	init_pin();
	uart_init();	
	init_interrupt();
	  /* send "Hello world -MCU" to terminal app on PC */
	  usart_send_string("Hello world -VHL");
    while(1)
    {

		#if 1
        if (0 != rx_data)
        {
            usart_send_byte(rx_data);
			led_on(GPIOD_BSRR , 12);
			delay(0xf);
			led_off(GPIOD_BSRR , 12);
			delay(0xf);
		
            rx_data = 0;
        }
        #else
        usart_send_byte(0x55);
        delay(0xf);
        #endif

    }

}
