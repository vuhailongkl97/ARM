#include "project.h"


void system_init(){
	
  volatile unsigned int temp_reg;
  volatile unsigned int timeout;
  
 
  /* Disable all interrupts */
   write_reg(RCC_CIR, 0x00000000U);
	
    write_reg(RCC_APB1ENR , (1u <<28 ));
   write_reg(RCC_APB2ENR , (1u <<14 ));
   
	
	//bat hse
	temp_reg = read_reg(RCC_CR, ~(1u << 16 ));
	temp_reg |= (1u << 16);
    write_reg(RCC_CR, temp_reg);
	
	timeout = 0xFF;
    do {
        temp_reg = read_reg(RCC_CR, (1u << 17));
        timeout--;
    } while ((0 == temp_reg) && (timeout > 0));
	

	/* Disable the main PLL. */
    temp_reg = read_reg(RCC_CR, ~(1 << 24));
    write_reg(RCC_CR, temp_reg);
	
	/* Wait till PLL is disable */
    timeout = 0xFF;
    do {
        temp_reg = read_reg(RCC_CR, (1 << 25));
        timeout--;
    } while ((0 != temp_reg) && (timeout > 0));
	
	
		// can thiet lap ko se doc sai dia chi lenh , du lieu 
	write_reg(FLASH_ACR , 0x01u);
	

	/* Configure the main PLL clock source, predivider and multiplication factor. */
	// chia /M chia 4
    temp_reg = read_reg(RCC_PLLCFGR, ~0x3Fu);
    temp_reg |= 0x08;
    write_reg(RCC_PLLCFGR, temp_reg);
    
	// nhan *N   *64
    temp_reg = read_reg(RCC_PLLCFGR, ~(0x1FFu << 6));
    temp_reg |= (64u << 6);
    write_reg(RCC_PLLCFGR, temp_reg);
	
	// chia /P  /4
    temp_reg = read_reg(RCC_PLLCFGR, ~(0x3u<< 16));
    temp_reg |= (1u<< 16);
    write_reg(RCC_PLLCFGR, temp_reg);
	
	
	/* Enable the main PLL. */
    temp_reg = read_reg(RCC_CR, ~(1 << 24));
    temp_reg |= (1 << 24);
    write_reg(RCC_CR, temp_reg);
	
	/* Wait till PLL is ready */
    timeout = 0xFFFF;
    do {
        temp_reg = read_reg(RCC_CR, (1 << 25));
        timeout--;
    } while ((0 == temp_reg) && (timeout > 0));
		

	
	/* Initializes the CPU, AHB and APB busses clocks */
    /* HCLK configration */
	//device to 2 ahb

    temp_reg = read_reg(RCC_CFGR, ~(0xFu << 4));
		temp_reg |= ( 8u << 4);
    write_reg(RCC_CFGR, temp_reg);	
	
	 /* APB1 prescaler */
	// chia toi da
    temp_reg = read_reg(RCC_CFGR, ~(0x07u << 10));
	temp_reg |= (0x07u << 10);
    write_reg(RCC_CFGR, temp_reg);
	// apb2
	temp_reg = read_reg(RCC_CFGR, ~(0x07u << 13));
	temp_reg |= (0x07u << 13);
    write_reg(RCC_CFGR, temp_reg);
	

		//select pll
    temp_reg = read_reg(RCC_CFGR, ~(0x3u << 0));
    temp_reg |= (2u << 0);
    write_reg(RCC_CFGR, temp_reg);
    
    // /* Wait till System clock switch is ready */
    timeout = 0xFFFFFF;
    do {
        temp_reg = read_reg(RCC_CFGR, (0x3 << 2));
        timeout--;
    } while (((2u<<2) != temp_reg) && (timeout > 0));
	

	
	temp_reg = read_reg(RCC_CFGR, ~(0xF << 4));
    temp_reg |= (0u<< 4);
    write_reg(RCC_CFGR, temp_reg);
	
    /* APB1 prescaler */
	// khong chia
    temp_reg = read_reg(RCC_CFGR, ~(7u << 10));
    write_reg(RCC_CFGR, temp_reg);
	
	  temp_reg = read_reg(RCC_CFGR, ~(7u << 13));
    write_reg(RCC_CFGR, temp_reg);

}

void rcc_enableclk(){
	unsigned int temp_reg;
	
	//port d 
	temp_reg = read_reg(RCC_AHB1ENR , ~(1 <<3));
	temp_reg  = temp_reg | (1 << 3 );
	write_reg(RCC_AHB1ENR , temp_reg );
	
	//port b
	temp_reg = read_reg(RCC_AHB1ENR , ~(1 <<1));
	temp_reg  = temp_reg | (1 << 1 );
	write_reg(RCC_AHB1ENR , temp_reg );
  
}