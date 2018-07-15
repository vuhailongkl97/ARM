#include "project.h"

void uart_init(){
	
	unsigned int temp_reg;
	
	//enable clock for uart
	temp_reg = read_reg(RCC_APB2ENR, ~(1u << 4));
    temp_reg |= (1 << 4);
    write_reg(RCC_APB2ENR, temp_reg);
	
	// Pb7 -RX
	temp_reg = read_reg(GPIOB_MODER , ~(3u << 14 ));
	temp_reg  = temp_reg | (GPIO_MODER_ALT << 14);
	write_reg(GPIOB_MODER , temp_reg );
	
	temp_reg = read_reg(GPIOB_PUPDR , ~(3u << 14 ));
	temp_reg  = temp_reg | (PULL_UP << 14);
	write_reg(GPIOB_PUPDR , temp_reg );
	
	
	temp_reg = read_reg(GPIOB_AFRL , ~(0x0Fu << 28 ));
	temp_reg  = temp_reg | (7u << 28);
	write_reg(GPIOB_AFRL , temp_reg );

	//Pb6 - TX
	
	temp_reg = read_reg(GPIOB_MODER , ~(3u << 12 ));
	temp_reg  = temp_reg | (GPIO_MODER_ALT << 12);
	write_reg(GPIOB_MODER , temp_reg );
	
	temp_reg = read_reg(GPIOB_PUPDR , ~(3u << 12 ));
	temp_reg  = temp_reg | (PULL_UP << 12);
	write_reg(GPIOB_PUPDR , temp_reg );
	
	temp_reg = read_reg(GPIOB_AFRL , ~(0x0Fu << 24 ));
	temp_reg  = temp_reg | (7u << 24);
	write_reg(GPIOB_AFRL , temp_reg );
	
	//DISABLE UART1
	temp_reg = read_reg(USART_CR1, ~(1<<13));
    write_reg(USART_CR1, temp_reg);

	// 1 stop 
	temp_reg = read_reg(USART_CR2 ,~(3 <<12));
	temp_reg |= (0 << 12);
	write_reg(USART_CR2 , temp_reg);		

	// data 8bit 	
	temp_reg = read_reg(USART_CR1 ,~(1 <<12));
	write_reg(USART_CR1 , temp_reg);
	
	//no  parity 
	temp_reg = read_reg(USART_CR1 ,~(1 <<10));
	write_reg(USART_CR1 , temp_reg);
	
	
	/* Clear CTSE and RTSE bits */
	temp_reg = read_reg(USART_CR1 ,~(3 <<8));
	write_reg(USART_CR1 , temp_reg);	
	
	//no  sampleing
	temp_reg = read_reg(USART_CR1 ,~(1 <<15));
	write_reg(USART_CR1 , temp_reg);
		
	//baudrate  
	//115200   0x0000008Bu
	//9600     0x00000683u  16mhz
	//temp_reg = 0x00000045u;
	
	
	//for 50Mhz , 9600bps
	//temp_reg = 0x00001458u;
	
	
	//temp_reg = 0x00000683u;  //16mhz
	temp_reg = 0x00000341u;   //8mhz
	
	temp_reg = 0x00000D05u;	//32mhz

	
	write_reg(USART_BRR , temp_reg);
	
	//ENABLE UART1
	temp_reg = read_reg(USART_CR1, ~(1<<13));
	temp_reg |= (1<<13);
    write_reg(USART_CR1, temp_reg);	
	
	/* Tx Enable */
    temp_reg = read_reg(USART_CR1, ~(1<<3));
    temp_reg |= (1 << 3);
    write_reg(USART_CR1, temp_reg);

    /* Rx Enable */
    temp_reg = read_reg(USART_CR1, ~(1<<2));
    temp_reg |= (1<<2);
    write_reg(USART_CR1, temp_reg);
	

}
char usart_send_byte(unsigned char data){
	
	unsigned int temp_reg ;
	// kiem tra TDR san sang nhan du lieu moi hay chua
	temp_reg = read_reg(USART_SR , (1 << 7));
	if( temp_reg != 0){
		// bat dau truyen 
		write_reg(USART_DR , (unsigned int)data);
		
		return 1;
	}
	return 0;
	
}
char usart_send_string( char *str){
	
		while(*str){
			if(usart_send_byte(*str))
				str++;
		}
	return 0;
}























