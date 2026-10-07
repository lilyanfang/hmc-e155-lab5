//lab5_INTERRUPT.c
//interrupt functions for lab 5

#include "lab5_EXTI.h"
#include "lab5_GPIO.h"
#include "lab5_INTERRUPT.h"
#include "lab5_RCC.h"
#include "lab5_SYSCFG.h"
#include "lab5_TIM.h"
#include <stdint.h>
#include <stdbool.h>

__STATIC_FORCEINLINE void __enable_irq(void) {
    __ASM volatile ("cpsie i" : : : "memory");
}

void interrupt(void) {
    //interrupt setup
    RCC->APB2ENR |= (1 << 0); //enable clock SYSCFG to GPIOA
    SYSCFG->EXTICR2 &= ~(111<<8); //set PA6 on line 6
    SYSCFG->EXTICR3 &= ~(111<<12); //set PA11 on line 11
    EXTI->IMR1 |= (1<<6); //unmask line 6
    EXTI->IMR1 |= (1<<11); //unmask line 11
    EXTI->RTSR1 |= (1<<6); //rising edge trigger for 6
    EXTI->RTSR1 |= (1<<11); //rising edge trigger for 11
    EXTI->FTSR1 |= (1<<6); //falling edge trigger for 6
    EXTI->FTSR1 |= (1<<11); //falling edge trigger for 11
    NVIC->ISER0 |= (1<<23); //bit 23 sets EXTI lines 9-5 interrupts
    NVIC->ISER1 |= (1<<8);  //bit 40 sets EXTI lines 15-10 interrupts
    __enable_irq(); //allow interrupts

}