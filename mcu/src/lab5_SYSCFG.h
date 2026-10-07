//lab5_SYSCFG.h
//header for SYSCFG functions

#ifndef LAB5_SYSCFG_H
#define LAB5_SYSCFG_H

#include <stdint.h> // Include stdint header

//definitions
#define __IO volatile

#define SYSCFG_BASE (0x40010000UL) //base address of SYSCFG

typedef struct {
    __IO uint32_t MEMRMP;   //00
    __IO uint32_t CFGR1;    //04
    __IO uint32_t EXTICR1;  //08
    __IO uint32_t EXTICR2;  //0c
    __IO uint32_t EXTICR3;  //10
    __IO uint32_t EXTICR4;  //14
    __IO uint32_t SCSR;     //18
    __IO uint32_t CFGR2;    //1c
    __IO uint32_t SWPR;     //20
    __IO uint32_t SKR;      //24
} SYSCFG_TypeDef;

#define SYSCFG ((SYSCFG_TypeDef *) SYSCFG_BASE)

#endif