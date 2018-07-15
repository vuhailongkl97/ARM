
#ifndef __MAIN_H__
#define __MAIN_H__


#define write_reg(addrs , value )    *((unsigned long  int * )(addrs))  = value
#define read_reg(addrs , mask )		 *((unsigned long  int * )(addrs))  & mask 




///////////////   BASE_ADDR      ///////////////

#define BASE_ADDR_GPI0C 0x40020C00u  
#define BASE_ADDR_GPI0A 0x40020000u  


#define GPIOD_MODER     (BASE_ADDR_GPI0C + 0x00u)
#define GPIOD_BSRR  (BASE_ADDR_GPI0C + 0x18u)


////////////////////////////////////////////


/////////////////// RCC /////////////////////////

#define BASE_RCC 0x40023800u  
#define RCC_CR          (BASE_RCC + 0x00u)
#define RCC_PLLCFGR     (BASE_RCC + 0x04u)
#define RCC_CFGR        (BASE_RCC + 0x08u)
#define RCC_CIR         (BASE_RCC + 0x0Cu)
#define RCC_AHB1ENR     (BASE_RCC + 0x30u)
#define RCC_APB2ENR		(BASE_RCC + 0x44u)
#define RCC_APB1ENR		(BASE_RCC + 0x40u)


////////////////////////////////////////////



///////////////   MODE PIN       ///////////////
#define GPIO_MODER_INPUT    0x00
#define GPIO_MODER_OUTPUT   0x01
#define GPIO_MODER_ALT  	0x02
#define GPIO_MODER_ANALOG   0x03
///////////////////////////////////////////////



////////////   PIN  LED  ////////////////
//led pd12 13 14 15
#define  led1   12
#define  led2   13
#define  led3   14
#define  led4   15

////////////////////////////

#define GPIOA_MODER   (BASE_ADDR_GPI0A + 0x00u)
#define GPIOA_IDR     (BASE_ADDR_GPI0A + 0x10u)
#define GPIOA_PUPDR   (BASE_ADDR_GPI0A + 0x0Cu)
#define GPIOA_AFRL    (BASE_ADDR_GPI0A + 0x20u)
#define GPIOA_AFRH    (BASE_ADDR_GPI0A + 0x24u)





/////////////   BUTTON   ///////////////
//button PA0
#define USER_BUTTON 0
// BUTTON PA1
#define USER_BUTTON1 1 

//////////////   BUTTON  /////////////
//  EXTI
#define BASE_EXTI 0x40013C00u
#define EXTI_IMR     (BASE_EXTI + 0x00u)
#define EXTI_EMR     (BASE_EXTI + 0x04u)
#define EXTI_RTSR     (BASE_EXTI + 0x08u)
#define EXTI_FTSR     (BASE_EXTI + 0x0Cu)
#define EXTI_PR     (BASE_EXTI + 0x14u)

///////////   SYSCFG   /////////////////
#define BASE_SYSCFG 0x40013800u
#define SYSCFG_EXTICR1 (BASE_SYSCFG +  0x08u)

////////////////////////////////////////////


/////////////////////NVIC  /////////////////
#define NVIC_ISER 0xE000E100u
#define NVIC_ISER1 0xE000E104u
#define NVIC_ICER 0XE000E180u
#define NVIC_ISPR 0XE000E200u
#define NVIC_ICPR 0XE000E280u
#define NVIC_IPR1 0xE000E404u
#define NVIC_IPR7 0xE000E428u


////////////////////////////////////////////
#define BASE_ADDR_UART   0x40011000u  
#define USART_SR      (BASE_ADDR_UART + 0x00u)
#define USART_DR      (BASE_ADDR_UART + 0x04u)
#define USART_BRR     (BASE_ADDR_UART + 0x08u)
#define USART_CR1     (BASE_ADDR_UART + 0x0Cu)
#define USART_CR2     (BASE_ADDR_UART + 0x10u)
#define USART_CR3     (BASE_ADDR_UART + 0x14u)
#define USART_GTPR    (BASE_ADDR_UART + 0x18u)


// PORT BASE_ADDR
#define GPIOB_BASE 0x40020400u
#define GPIOB_MODER   (GPIOB_BASE + 0x00u)
#define GPIOB_AFRL    (GPIOB_BASE + 0x20u)
#define GPIOB_PUPDR    (GPIOB_BASE + 0x0Cu)


#define NO_PULL 	0
#define PULL_UP 	1
#define PULL_DOWN   2


//flash

#define BASE_FLASH 0x40023C00u
#define FLASH_ACR ( BASE_FLASH +0x00u) 









 































#endif