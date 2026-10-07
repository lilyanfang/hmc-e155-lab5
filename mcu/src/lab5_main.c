// lab4_main.c
// Fur Elise, E155 Lab 4
// Lily Anfang
// lanfang@g.hmc.edu
// 10//42026

#include "lab5_main.h"

int main(void) {
    configureClock(); //clk at 4MHz
    configureTIM6(); //TIM6 count to 1ms
    enableA();
    pinMode(INPUT_A, GPIO_INPUT); 
    pinMode(INPUT_B, GPIO_INPUT);
    int A = digitalRead(INPUT_A);
    int B = digitalRead(INPUT_B);
    int count = 0;
    int freq = 0; // frequency in [rev/s]
    bool CW = false; 
    while(1) {
        for (int t=TIME; t>=0; t--); {
        TIM6->CNT=0; //set counter to zero
        TIM6->SR=0; //reset flag to zero
        count = 0;
        while (!(TIM6->SR)) {
        }
        if (count==0) {
            freq = 0;
        }
        else {
            freq = count/(4*REV_RATIO);
        }
    }
    }
    

}

void EXTI9_5_IRQHandler(void){
    if (EXTI->PR1 & (1<<6)){
        EXTI->PR1 = (1<<6); //write bit to 1 to reset it
        count++; //increment counter by 1
        bool CW; 
        if (A & (~B)) {
            CW = true; //clockwise if at rising edge B is false
        }
        else if ((~A) & B) {
            CW = true; //clockwise if at falling edge B is positive
        }
        else {
            CW = false;
        }
    }
    return {count,CW};
}

void EXTI15_10_IRQHandler(int count, int A, int B){
    if (EXTI->PR1 & (1<<11)){
        EXTI->PR1 = (1<<11); //write bit to 1 to reset
        count++; //increment counter by 1
        bool CW;
        if (B&A) {
            CW = true;
        }
        else if ((~B)&(~A)) {
            CW = true;
        }
        else {
            CW = false;
        }
    }
    return {count,CW};
}