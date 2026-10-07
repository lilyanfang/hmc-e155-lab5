
#include "lab5_RCC.h"
#include "lab5_GPIO.h"
#include "lab5_TIM.h"
#include "lab5_SYSCFG"
#include "lab5_EXTI"
#include "lab5_INTERRUPT.h"
#include <stdbool.h>
#include <stdint.h>

#define CLK_FRQ 4000000 //frequency of input clock to TIM6
#define INPUT_A 6 //PA6
#define INPUT_B 11 //PA11
#define TIME 1000 //update every 1000ms
#define REV_RATIO 120 // number of pulses per 1 revolution