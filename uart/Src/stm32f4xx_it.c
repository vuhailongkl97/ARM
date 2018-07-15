
#include "project.h"

extern int times;
volatile unsigned int led_state = 0;
volatile unsigned char rx_data = 0;

void EXTI1_IRQHandler(){
	unsigned int temp_reg;
	delay(0xfff);
	// xoa co ngat 
	temp_reg = (1 <<1) ;
	write_reg(EXTI_PR , temp_reg );
	write_reg(NVIC_ICPR , (1 << 7) );
}
void EXTI0_IRQHandler(){
	unsigned int temp_reg;
	
	times = !times;
	if(times)
		led_on(GPIOD_BSRR,15);
	else 
		led_off(GPIOD_BSRR,15);

	// xoa co ngat 
	temp_reg = (1 <<0) ;
	write_reg(EXTI_PR , temp_reg );
	write_reg(NVIC_ICPR , (1 << 6) );
	
}

void init_interrupt( ){
	unsigned int temp_reg;
//EXTI_IMR enable 2 interrupt EXTI0 , EXTI1
	temp_reg = read_reg(EXTI_IMR , ~(0x03<< 0));
	temp_reg  = temp_reg | (0x03<< 0 );
	write_reg(EXTI_IMR , temp_reg );
	
	
	/////////////////////////////
	//raising for button1 
	temp_reg = read_reg(EXTI_RTSR , ~(1<< 0));
	temp_reg  = temp_reg | (1<< 0 );
	write_reg(EXTI_RTSR , temp_reg );
	
	// raising for button1
	temp_reg = read_reg(EXTI_RTSR , ~(1u<< 1));
	temp_reg  = temp_reg | (1u << 1 );
	write_reg(EXTI_RTSR , temp_reg );
	
	/////////////////////////////
// syscfg
	
	//FOR EXTI0
	temp_reg = read_reg(SYSCFG_EXTICR1 , ~(0x0F<< 0));
	temp_reg  = temp_reg | (0 << 0 );
	write_reg(SYSCFG_EXTICR1 , temp_reg );
	
	//FOR EXTI1
	temp_reg = read_reg(SYSCFG_EXTICR1 , ~(0x0F<< 4));
	temp_reg  = temp_reg | (0 << 4 );
	write_reg(SYSCFG_EXTICR1 , temp_reg );
	
	//////////////////////////////
	
//NVIC	
	//FOR EXTI0
	temp_reg = read_reg(NVIC_IPR1 , ~(0xFF << 16));
	temp_reg  = temp_reg | (1u << 22 );
	write_reg(NVIC_IPR1 , temp_reg );
	
	//FOR EXTI0	
	temp_reg = read_reg(NVIC_IPR1 , ~(0xFF << 24));
	temp_reg  = temp_reg | (0x01 << 30 );
	write_reg(NVIC_IPR1 , temp_reg );
	
	
	//////////////////////////////
	// enable nvic
	
	//EXTI0
	temp_reg = read_reg(NVIC_ISER , ~(0x01<< 6));
	temp_reg  = temp_reg | (1 << 6 );
	write_reg(NVIC_ISER , temp_reg );
	
	//EXTI1
	temp_reg = read_reg(NVIC_ISER , ~(0x01<< 7));
	temp_reg  = temp_reg | (1 << 7 );
	write_reg(NVIC_ISER , temp_reg );
	
	//////////////////////////////
	/* usart1 */

	
    /* Tx interrupt */
    temp_reg = read_reg(USART_CR1, ~(1 << 6));
    temp_reg |= (1 << 6);
    write_reg(USART_CR1, temp_reg);

    /* Rx interrupt - RXNEIE */
    temp_reg = read_reg(USART_CR1, ~(1 << 5));
    temp_reg |= (1 << 5);
    write_reg(USART_CR1, temp_reg);
    
    // 37  = 32 + 5
    temp_reg = read_reg(NVIC_ISER1, ~(1 << 5));
    temp_reg |= 1 << 5;
    write_reg(NVIC_ISER1, temp_reg);

    temp_reg = read_reg(NVIC_IPR7, ~(0xFF << 8));
    temp_reg |= 0x01 << 14;
    write_reg(NVIC_IPR7, temp_reg);
    
	
	
    asm("cpsie i") ;	
	
}

void USART1_IRQHandler(void)
{
    volatile unsigned int temp;
	unsigned long int temp_reg;
    
    temp = read_reg(USART_SR, 1 << 6);
    if (0 != temp) /* Tx - TC flag */
    {
		// clear flag tc
		temp_reg = read_reg(USART_SR , ~(1u << 6));
		temp_reg |= (0u << 6);
        write_reg(USART_SR, temp_reg);
		
    }
    temp = read_reg(USART_SR, 1 << 5);
    if (0 != temp)  /* Rx - RXNE flag */
    {
        rx_data = read_reg(USART_DR , 0x000000FF);
    }
}
void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1)
  {
  }
}
void MemManage_Handler(void)
{
  while (1)
  {
  }
}

void BusFault_Handler(void)
{
  while (1)
  {
  }

}

void UsageFault_Handler(void)
{
  while (1)
  {
  }
}
void SVC_Handler(void)
{
}

void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}

void SysTick_Handler(void)
{
}






















