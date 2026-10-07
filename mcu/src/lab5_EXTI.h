//lab5_EXTI.h
//header for EXTI functions

#ifndef LAB5_EXTI_H
#define LAB5_EXTI_H

#include <stdint.h> // Include stdint header

//definitions
#define __IO volatile

#define EXTI_BASE (0x40010400UL) //base address of EXTI

typedef struct {
    __IO uint32_t IMR1;     //00
    __IO uint32_t EMR1;     //04
    __IO uint32_t RTSR1;    //08
    __IO uint32_t FTSR1;    //0c
    __IO uint32_t SWIER1;   //10
    __IO uint32_t PR1;      //14
    __IO uint32_t RESERVED1; //18
    __IO uint32_t RESERVED2; //1c
    __IO uint32_t IMR2;     //20
    __IO uint32_t EMR2;     //24     
    __IO uint32_t RTSR2;    //28    
    __IO uint32_t FTSR2;    //2c
    __IO uint32_t SWIER2;   //30
    __IO uint32_t PR2;      //34
} EXTI_TypeDef;

#define EXTI ((EXTI_TypeDef *) EXTI_BASE)

#endif