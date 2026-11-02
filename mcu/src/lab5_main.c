// lab5_main.c
//  E155 Lab 5
// Lily Anfang
// lanfang@g.hmc.edu
// 

#include "lab5_main.h"

volatile float count;
volatile int CWcount;
volatile int CCWcount;
volatile bool CW;


int _write(int file, char *ptr, int len) {
  int i = 0;
  for (i=0; i<len; i++) {
    ITM_SendChar((*ptr++));
  }
  return len;
}

void EXTI9_5_IRQHandler(void){
    int A = digitalRead(INPUT_A);
    int B = digitalRead(INPUT_B);
    if (EXTI->PR1 & (1<<6)){
        EXTI->PR1 = (1<<6); //write bit to 1 to reset it
        count++; //increment counter by 1 
        if (A & (~B)) {
            CWcount++; //clockwise if at rising edge B is false
        }
        else if ((~A) & B) {
            CWcount++; //clockwise if at falling edge B is positive
        }
        else if (A&B) {
            CCWcount++;
        }
        else if ((~A)&(~B)) {
            CCWcount++;
        }
    }
}

void EXTI15_10_IRQHandler(void){
    int A = digitalRead(INPUT_A);
    int B = digitalRead(INPUT_B);
    if (EXTI->PR1 & (1<<11)){
        EXTI->PR1 = (1<<11); //write bit to 1 to reset
        count++; //increment counter by 1
        if (B&A) {
            CWcount++;
        }
        else if ((~B)&(~A)) {
            CWcount++;
        }
        else if ((~B)&A) {
            CCWcount++;
        }
        else if (B&(~A)) {
            CCWcount++;
        }
    }
}

int main(void) {
    //configureClock(); //clk at 4MHz
    configureTIM6(); //TIM6 count to 1ms
    enableA();
    interrupt();
    pinMode(INPUT_A, GPIO_INPUT); 
    pinMode(INPUT_B, GPIO_INPUT);
    CWcount = 0;
    CCWcount = 0;
    count = 0;
    float freq = 0; // frequency in [rev/s]
    CW = false; 
    while(1) {
      count = 0;
      CWcount = 0;
      CCWcount = 0;
      for (int t=TIME; t>0; t--) {
        TIM6->CNT=0; //set counter to zero
        TIM6->SR=0; //reset flag to zero
        while (!(TIM6->SR));
      }
      if (count==0) {
        freq = 0;
      }
      else {
        freq = count/(4*REV_RATIO);
      }
      CW = (CWcount > CCWcount);
      printf("%f", freq);
      if (CW) {
        printf(" CW \n");
      }
      else if (~CW) {
        printf(" CCW \n");
      }
    }
}