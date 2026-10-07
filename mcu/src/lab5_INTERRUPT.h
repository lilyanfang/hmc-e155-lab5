//lab5_INTERRUPT.h
//header for interrupt functions

#ifndef LAB5_INTERRUPT_H
#define LAB5_INTERRUPT_H

#include <stdint.h> // Include stdint header

#define __IO volatile

#define NVIC_BASE (0xE000E100UL) //base address for NVIC

typedef struct{
    __IO uint32_t ISER0; //00
    __IO uint32_t ISER1; //04
    __IO uint32_t ISER2; //08
    __IO uint32_t ISER3; //0c
    __IO uint32_t ISER4; //10
    __IO uint32_t ISER5; //14
    __IO uint32_t ISER6; //18
    __IO uint32_t ISER7; //1c
} NVIC_TypeDef;

#define NVIC ((NVIC_TypeDef *) NVIC_BASE)

void interrupt(void);
#endif