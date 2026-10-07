// lab5_RCC.c
// Source code for RCC functions

#include "lab5_RCC.h"

void configurePLL() {
    // Set clock to 80 MHz
    // Output freq = (src_clk) * (N/M) / R
    // (4 MHz) * (N/M) / R = 80 MHz
    // M: XX, N: XX, R: XX
    // Use MSI as PLLSRC

    // TODO: Turn off PLL
    RCC->CR&=~(1<<24);
    // TODO: Wait till PLL is unlocked (e.g., off)
    while ((RCC->CR>>25)&1!=0);

    // Load configuration
    // TODO: Set PLL SRC to MSI (PLLSRC=01)
    RCC->PLLCFGR&=~(1<<1); //bit 1 is 0
    RCC->PLLCFGR|=1; //bit 0 is 1

    // TODO: Set PLLN
    RCC->PLLCFGR&=~(0b1111111<<8);
    RCC->PLLCFGR|= (0b1010000<<8);

    // TODO: Set PLLM
    RCC->PLLCFGR &= ~(0b111 << 4);

    // TODO: Set PLLR
    RCC->PLLCFGR &= ~(1 << 26);
    RCC->PLLCFGR |= (1 << 25);
    
    // TODO: Enable PLLR output
    RCC->PLLCFGR |= (1 << 24);

    // TODO: Enable PLL
    RCC->CR |= (1 << 24);  
    
    // TODO: Wait until PLL is locked
    while ((RCC->CR >> 25 & 1) != 1);  
}

void configureClock(){
    
    // Select MSI as clock source
    RCC->CR |= (1 << 0);
    
}