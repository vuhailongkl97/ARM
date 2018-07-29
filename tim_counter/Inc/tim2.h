#ifndef __TIM2_H__
#define __TIM2_H__

void counter2_config();
void counter2_start();
void TIM_Base_Init();
void TIM_SlaveConfigSynchronization();
void TIMEx_MasterConfigSynchronization();
void mTIM_Base_SetConfig(u32_t arr , u32_t psc );



#endif
