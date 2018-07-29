#include "project.h"

// 1. Configure the timers to use the TIx pin as input:
// a) Select the pin to be used by writing CCxS bits in the TIMx_CCMR1 register.
// b) Select the polarity of the input:
// For the STM32F100/101/102/103/105/107 lines: by writing CCxP in the
// TIMx_CCER register to select the rising or the falling edge;
// For the other series & lines: by writing CCxP and CCxNP in the TIMx_CCER
// register to select the rising/falling edge, or both edges (a) .
// c) Enable corresponding channel by setting the CCEx bit in the TIMx_CCER register.
// 2. Select the timer TIx as the trigger input source by writing TS bits in the TIMx_SMCR
// register.
// 3. Select the external clock mode1 by writing SMS=111 in the TIMx_SMCR register.
void config_ext_clk1(){
	u32_t temp_reg;
	// 1. Configure the timers to use the TIx pin as input:
	//Select the pin to be used by writing CCxS bits in the TIMx_CCMR1 register.
	temp_reg = read_reg(TIM_CCMR1(mTIM2) , ~2u);
	// use as output
	write_reg(TIM_CCMR1(mTIM2) , temp_reg);
	
	// b) Select the polarity of the input:
	// TIMx_CCER register to select the rising or the falling edge;
	// For the other series & lines: by writing CCxP and CCxNP in the TIMx_CCER
	// register to select the rising/falling edge, or both edges (a) .
	//TI1FP1 rising edge
	temp_reg = read_reg(TIMx_CCER(mTIM2) , ~0xFU);
	write_reg(TIMx_CCER(mTIM2) , temp_reg);
	
	
	
	// c) Enable corresponding channel by setting the CCEx bit in the TIMx_CCER register.
	temp_reg = read_reg(TIM_CCR1(mTIM2) , ~1U);
	temp_reg |= 1U;
	write_reg(TIM_CCR1(mTIM2) , temp_reg);
	
	
	
	
	// 2. Select the timer TIx as the trigger input source by writing TS bits in the TIMx_SMCR
	// register.  Filtered Timer Input 1
	temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u << 4));
	temp_reg |= (5U<<4);
	write_reg(TIM_SMCR(mTIM2) , temp_reg);
	
	
	// 3. Select the external clock mode1 by writing SMS=111 in the TIMx_SMCR register.
	
	temp_reg = read_reg(TIM_SMCR(mTIM2) , ~(7u << 0));
	temp_reg |= 7U;
	write_reg(TIM_SMCR(mTIM2) , temp_reg);
	
	temp_reg = read_reg(TIM_EGR(mTIM2) , ~1u);
	temp_reg |= 1u;
	write_reg(TIM_EGR(mTIM2) , temp_reg);
}
void input_capture_config(){
	u32_t temp_reg;
	// Select the active input:01: CC1 channel is configured as input, IC1 is mapped on TI1.
	temp_reg = read_reg(TIM_CCMR1(mTIM2), ~3u);
	//01: CC1 channel is configured as input, IC1 is mapped on TI1.
	temp_reg |= 1u;
	
	// IC1F Input capture 1 filter
	
	temp_reg |= (15u << 4);
	write_reg(TIM_CCMR1(mTIM2) , temp_reg);
	
	
	// Select the edge of the active transition on the TI1 channel by writing the CC1P and
	// CC1NP bits to 00 in the TIMx_CCER register (rising edge in this case).
	
	temp_reg = read_reg(TIMx_CCER(mTIM2) , ~0xFU);
	write_reg(TIMx_CCER(mTIM2) , temp_reg);
	
	// Program the input prescaler. In our example, we wish the capture to be performed at
	// each valid transition, so the prescaler is disabled (write IC1PS bits to 00 in the
	// TIMx_CCMR1 register).
	
	
	temp_reg = read_reg(TIM_CCMR1(mTIM2) , ~(3u << 2));
	write_reg(TIM_CCMR1(mTIM2) , temp_reg);
	
	// Enable capture from the counter into the capture register by setting the CC1E bit in the
	// TIMx_CCER register.
	
	temp_reg = read_reg(TIMx_CCER(mTIM2) , ~(3u << 2));
	temp_reg |=1U;
	write_reg(TIMx_CCER(mTIM2) , temp_reg);
	
	
	// If needed, enable the related interrupt request by setting the CC1IE bit in the
	// TIMx_DIER register, and/or the DMA request by setting the CC1DE bit in the
	// TIMx_DIER register
	
	// An interrupt is generated depending on the CC1IE bit.
	temp_reg = read_reg(TIM_DIER(mTIM2) , ~(1u << 1));
	temp_reg |=(1U<<1);
	write_reg(TIM_DIER(mTIM2) , temp_reg);

}

























