#include "project.h"
void counter2_start(){
	
	u32_t temp_reg;
	  /* Enable the TIM Update interrupt UIE*/ 
	 temp_reg = read_reg(TIM_DIER(mTIM2) , ~1u);
	 temp_reg |=1u;
	 write_reg(TIM_DIER(mTIM2) , temp_reg);
	  	  
	  /* Enable the Peripheral cr1 cen*/
	  //__HAL_TIM_ENABLE(htim);
	 temp_reg = read_reg(TIM_CR1(mTIM2) , ~1u);
	 temp_reg |=1u;
	 write_reg(TIM_CR1(mTIM2) , temp_reg);
	
}
void counter2_config(){	
	TIM_Base_Init();
	config_ext_clk1();
	// mTIM_Base_SetConfig(10u , 0u);
	// TIM_SlaveConfigSynchronization();
	// TIMEx_MasterConfigSynchronization();
		
}
void TIM_Base_Init(){
	/* Init the low level hardware :CLOCK , GPIO, NVIC */
    //HAL_TIM_Base_MspInit(htim);
	//1.enable clock 
	//2.config gpio
	//3.set priority & enable interrupt
	u32_t temp_reg ;
	mGPIO_TypeDef GPIO_Init;
	GPIO_Init.mpin  =  GPIO_PIN(0);
	GPIO_Init.moder = GPIO_MODER_ALT;
	GPIO_Init.type = PUSH_PULL;
	GPIO_Init.pull  = NO_PULL;
	GPIO_Init.speed = FAST_SPEED;
	GPIO_Init.alternate = 1; 
	
	/* Peripheral clock enable */
	temp_reg = read_reg(RCC_APB1ENR , ~0u);
	temp_reg |= (1u << 0 );
	write_reg(RCC_APB1ENR , temp_reg);
	

	init_pin(GPIOA , &GPIO_Init);
	
	mNVIC_SetPriority(TIM2_IRQn, 0);
	mNVIC_EnableIRQ(TIM2_IRQn);
	

}
void mTIM_Base_SetConfig(u32_t arr , u32_t psc ){
	u32_t temp_reg;
	/* Set the Time Base configuration */
	/* 1.Select the Counter Mode CR1*/ 
	 
	 /* Set TIM Time Base Unit parameters ---------------------------------------*/
	// dem suon len 
	temp_reg = read_reg(TIM_CR1(mTIM2), ~(0x07u<<4));
	temp_reg |=  0u<< 4;
	write_reg(TIM_CR1(mTIM2) , temp_reg);
	
	//ckd ClockDivision /1
	temp_reg = read_reg(TIM_CR1(mTIM2) , ~(3u << 8));
	write_reg(TIM_CR1(mTIM2) , temp_reg);
	
	
	/* Set the Auto-reload value  = 10 */
	write_reg(TIM_ARR(mTIM2) , arr);	
	
	/* Set the Prescaler value  */
	write_reg(TIM_PSC(mTIM2) , psc);	


	/* Generate an update event to reload the Prescaler 
	and the repetition counter(only for TIM1 and TIM8) value immediately */
	temp_reg = read_reg(TIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(TIM_EGR(mTIM2) , temp_reg);	
}
void TIM_SlaveConfigSynchronization(){
	u32_t temp_reg , tmpccer , tmpccmr1;
	//TIM_SlaveTimer_SetConfig(htim, sSlaveConfig);
    /* Set the Time Base configuration */
		/* Set the Input Trigger source */
		temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u <<4));
		temp_reg |= (5u <<4);
		write_reg(TIM_SMCR(mTIM2) , temp_reg);	
		
		/* Set the slave mode */
		temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u <<0));
		temp_reg |= 7u;
		write_reg(TIM_SMCR(mTIM2) , temp_reg);
	
    	/* Configure the trigger prescaler, filter, and polarity */  
					  
			tmpccer = read_reg(TIMx_CCER(mTIM2) , ~(1u <<0));
			tmpccmr1 = read_reg(TIM_CCMR1(mTIM2) , ~0U);

			/* Set the filter */

			tmpccmr1   &= ~(0xFu << 4);
			tmpccmr1   |= (15u << 4);

			// /* Select the Polarity and set the CC1E Bit */
			// tmpccer &= ~(TIM_CCER_CC1P | TIM_CCER_CC1NP);
			// tmpccer |= TIM_ICPolarity;
			tmpccer  &= ~(1u <<0 | 1u << 3);
			tmpccer |= 0u;
			
			write_reg(TIMx_CCER(mTIM2) , tmpccer);
			write_reg(TIM_CCMR1(mTIM2) , tmpccmr1);
							
			// /* Disable Trigger Interrupt */		
			temp_reg = read_reg(TIM_DIER(mTIM2) , ~(1u << 6));
			write_reg(TIM_DIER(mTIM2) , temp_reg);
			

			// /* Disable Trigger DMA request */
			temp_reg = read_reg(TIM_DIER(mTIM2) , ~(1u << 14));
			write_reg(TIM_DIER(mTIM2) , temp_reg);			

	
}
void TIMEx_MasterConfigSynchronization(){
		u32_t temp_reg;
	  /* Reset the MMS Bits */
		 /* Select the TRGO source */
		temp_reg  = read_reg(TIM_CR2(mTIM2) , ~(7u << 4));
		write_reg(TIM_CR2(mTIM2) , temp_reg);
		
		// /* Set or Reset the MSM Bit */
		// htim->Instance->SMCR |= sMasterConfig->MasterSlaveMode;
		temp_reg  = read_reg(TIM_SMCR(mTIM2) , ~(1u << 7));
		write_reg(TIM_SMCR(mTIM2) , temp_reg);
}



















