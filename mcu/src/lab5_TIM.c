// lab5_TIM.c
// source code for configuring TIM6 & TIM7

#include "lab5_TIM.h"
#include "lab5_RCC.h"

//configure TIM6 to count 1ms
void configureTIM6() {
    //enable TIM6 clock
    RCC->APB1ENR1 |=(1<<4);

    //cofigure URS so only overflow triggers an update event
    TIM6->CR1 |=  (1<<2); 

    //configure Arr so it divides the clock by 4000 (1ms)
    TIM6->ARR = 3999u;

    //enable counter
    TIM6->CR1 |= (1<<0);

}