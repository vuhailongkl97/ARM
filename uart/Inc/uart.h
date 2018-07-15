#ifndef __UART_H__
#define __UART_H__

void uart_init();
char usart_send_byte(unsigned char data);
char usart_send_string( char *str);

#endif
