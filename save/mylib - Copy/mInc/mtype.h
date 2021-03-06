
#ifndef __MTYPE_H__
#define __MTYPE_H__

typedef unsigned int u32_t;
typedef unsigned char u8_t;

typedef struct{
	u32_t  mpin;
	u32_t  moder;
	u32_t  type;
	u32_t  pull;
	u32_t  speed;
	u32_t  alternate;
}mGPIO_TypeDef;

#define ENABLE  1U
#define DISABLE 0U



///////////////   BASE_ADDR      ///////////////
#define BASE_ADDR 0x40020000u


#define mGPIOA (BASE_ADDR + 0x00u) 
#define mGPIOB (BASE_ADDR + 0x400u)
#define mGPIOC (BASE_ADDR + 0x800u)
#define mGPIOD (BASE_ADDR + 0xC00u)
#define mGPIOE (BASE_ADDR + 0x1000u)
#define mGPIOG (BASE_ADDR + 0x1C00u)


#define mGPIO_MODER(GPIO)   (GPIO + 0x00u)
#define mGPIO_OTYPER(GPIO)  (GPIO + 0x04u)
#define mGPIO_OSPEEDR(GPIO) (GPIO + 0x08u)
#define mGPIO_PUPDR(GPIO)   (GPIO + 0x0Cu)
#define mGPIO_IDR(GPIO)     (GPIO + 0x10u)
#define mGPIO_ODR(GPIO)     (GPIO + 0x14u)
#define mGPIO_BSRR(GPIO)    (GPIO+ 0x18u)
#define mGPIO_AFRL(GPIO)    (GPIO + 0x20u)
#define mGPIO_AFRH(GPIO)    (GPIO + 0x24u)

///////////////   MODE PIN       ///////////////
#define mGPIO_MODER_INPUT    0x00
#define mGPIO_MODER_OUTPUT   0x01
#define mGPIO_MODER_ALT  	0x02
#define mGPIO_MODER_ANALOG   0x03


#define mPUSH_PULL  0u
#define mOPEN_DRAIN 1u


#define mNO_PULL 	0u
#define mPULL_UP 	1u
#define mPULL_DOWN   2u

#define mLOW_SPEED   	0u
#define mMEDIUM_SPEED   	1u
#define mFAST_SPEED   	2u
#define mHIGH_SPEED   	3u

#define mGPIO_PIN(n)     (1 << n)


/////////////////// RCC /////////////////////////

#define mBASE_RCC		 0x40023800u  
#define mRCC_CR          (mBASE_RCC + 0x00u)
#define mRCC_PLLCFGR     (mBASE_RCC + 0x04u)
#define mRCC_CFGR        (mBASE_RCC + 0x08u)
#define mRCC_CIR         (mBASE_RCC + 0x0Cu)
#define mRCC_AHB1ENR     (mBASE_RCC + 0x30u)
#define mRCC_APB1ENR		(mBASE_RCC + 0x40u)
#define mRCC_APB2ENR		(mBASE_RCC + 0x44u)


// /M *N /P
// M , N khong can tinh ( nhu thap phan )

#define mPLLP_DIV2 0u
#define mPLLP_DIV4 1u
#define mPLLP_DIV6 2u
#define mPLLP_DIV8 3u

//APBx
#define mAPB_DIV1  0u
#define mAPB_DIV2  4u
#define mAPB_DIV4  5u
#define mAPB_DIV8  6u
#define mAPB_DIV16 7u

// AHB pmrescaler
#define mAHB_DIV1  	0u
#define mAHB_DIV2  	8u
#define mAHB_DIV4  	9u
#define mAHB_DIV8  	10u
#define mAHB_DIV16	11u
#define mAHB_DIV64 	12u
#define mAHB_DIV128	13u
#define mAHB_DIV256 	14u
#define mAHB_DIV512 	15u

#define mSRC_HSI 0u
#define mSRC_HSE 1u
#define mSRC_PLL 2u


//  EXTI
#define mBASE_EXTI 0x40013C00u
#define mEXTI_IMR      (mBASE_EXTI + 0x00u)
#define mEXTI_EMR      (mBASE_EXTI + 0x04u)
#define mEXTI_RTSR     (mBASE_EXTI + 0x08u)
#define mEXTI_FTSR     (mBASE_EXTI + 0x0Cu)
#define mEXTI_PR       (mBASE_EXTI + 0x14u)

////////m///   SYSCFG   /////////////////
#define mBASE_SYSCFG 0x40013800u
#define mSYSCFG_EXTICR1 (mBASE_SYSCFG +  0x08u)

////////m////////////////////////////////////


////////m/////////////NVIC  /////////////////
#define mNVIC_ISER(x) (0xE000E100u + (4*x) )
#define mNVIC_ICER 0XE000E180u
#define mNVIC_ISPR 0XE000E200u
#define mNVIC_ICPR 0XE000E280u
#define mNVIC_IPR(x) (0xE000E400 + (4*x) )



////////m////////////////////////////////////
#define mUSART1   0x40011000u  
#define mUSART_SR(uart)      (uart + 0x00u)
#define mUSART_DR(uart)      (uart + 0x04u)
#define mUSART_BRR(uart)     (uart + 0x08u)
#define mUSART_CR1(uart)     (uart + 0x0Cu)
#define mUSART_CR2(uart)     (uart + 0x10u)
#define mUSART_CR3(uart)     (uart + 0x14u)
#define mUSART_GTPR(uart)    (uart + 0x18u)


//flash
#define mBASE_FLASH 0x40023C00u
#define mFLASH_ACR ( mBASE_FLASH +0x00u) 

// systimck 
#define mSYST_CSR 0xE000E010
#define mSYST_RVR 0xE000E014
#define mSYST_CVR 0xE000E018
#define mSYST_CALIB 0xE000E01C

//POWWERm
#define mPWR 0x40007000u
#define mPWR_CR (mPWR + 0x00u)


// mTIM2
#define  mTIM2   0x40000000u
#define  mTIM4   0x40000800u



#define mTIM_CR1(x)    ( x + 0u )
#define mTIM_CR2(x)    ( x + 4u )
#define mTIM_SMCR(x)   ( x + 8u )
#define mTIM_DIER(x)   ( x + 12u )
#define mTIM_SR(x)     ( x + 16u )
#define mTIM_EGR(x)    ( x + 20u )
#define mTIM_CCMR1(x)  ( x + 24u )
#define mTIM_CCMR2(x)  ( x + 28u )
#define mTIM_CCER(x)  ( x + 32u )
#define mTIM_CNT(x)    ( x + 36u )
#define mTIM_PSC(x)    ( x + 40u )
#define mTIM_ARR(x)    ( x + 44u )
#define mTIM_CCR1(x)   ( x + 52u )
#define mTIM_CCR2(x)   ( x + 56u )
#define mTIM_CCR3(x)   ( x + 60u )
#define mTIM_CCR4(x)   ( x + 64u )
#define mTIM_DCR(x)    ( x + 72u )
#define mTIM_DMAR(x)   ( x + 76u )
#define mTIM2_OR     ( mTIM2 + 80u )


//FPU Flmoat Pointing Uinit
#define mFPU_CPACR  0xE000ED88  
#define mFPU_FPCCR  0xE000EF34   
#define mFPU_FPCAR  0xE000EF38 
#define mFPU_FPDSCR 0xE000EF3C  


//DMA
#define mDMA1   0x40026000u    
#define mDMA2   0x40026400u

//DMA_LIFCR

#define mDMA_LISR(dma)            (dma + 0x0u)
#define mDMA_HISR(dma)            (dma + 0x4u)
#define mDMA_LIFCR(dma)           (dma + 0x8u)
#define mDMA_HIFCR(dma)           (dma + 0xCu)
#define mDMA_SxCR(dma,stream)     (dma + 0x10 + 0x18*stream)
#define mDMA_SxNDTR(dma,stream)   (dma + 0x14 + 0x18*stream)
#define mDMA_SxPAR(dma,stream)    (dma + 0x18 + 0x18*stream)
#define mDMA_SxM0AR(dma,stream)   (dma + 0x1C + 0x18*stream)
#define mDMA_SxM1AR(dma,stream)   (dma + 0x20 + 0x18*stream)
#define mDMA_SxFCR(dma,stream)    (dma + 0x24 + 0x18*stream)

#define DMA_P2M 0U
#define DMA_M2P 1U
#define DMA_M2M 0U


#define DMA_FIX 0U
#define DMA_INC 1U


#define DMA_SIZE_BYTE  0U
#define DMA_SIZE_HWORD 1U
#define DMA_SIZE_WORD  2U


#define DMA_PL_LOW    0U
#define DMA_PL_MEDIUM 1U
#define DMA_PL_HIGH   2U
#define DMA_PL_VHIGH  3U













    



#endif
