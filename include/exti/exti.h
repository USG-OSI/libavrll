#ifndef EXTI_H
#define EXTI_H

#include "types.h"

typedef enum {
    EXTI_LOW_LEVEL = 0,
    EXTI_ANY_CHANGE,
    EXTI_FALLING_EDGE,
    EXTI_RISING_EDGE
} exti_sense_t;

void exti_int0_init(exti_sense_t sense_mode);
void exti_int1_init(exti_sense_t sense_mode);

void exti_int0_enable(void);
void exti_int1_enable(void);

void exti_int0_disable(void);
void exti_int1_disable(void);

void exti_int0_clear_flag(void);
void exti_int1_clear_flag(void);

#endif