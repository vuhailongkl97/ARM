
#ifndef __MAIN_H__
#define __MAIN_H__


#define write_reg(addrs , value )    *((unsigned long  int * )(addrs))  = value
#define read_reg(addrs , mask )		 *((unsigned long  int * )(addrs))  & mask 

/* USER CODE END Private defines */
#define BASE_ADDR_GPI0C 0x40020C00u  
#define GPIOD_MODER     (BASE_ADDR_GPI0C + 0x00u)

// rcc- clock
#define BASE_RCC_AHB1ENR 0x40023800u
#define RCC_AHB1ENR     (BASE_RCC_AHB1ENR + 0x30u)



#define GPIO_MODER_INPUT  0x00

#define GPIO_MODER_OUTPUT  0x01

#define GPIO_MODER_ALT  0x02

#define GPIO_MODER_ANALOG  0x03

#define GPIOD_BSRR     (BASE_ADDR_GPI0C + 0x18u)

//led pd12  14
#define  led   14

#endif