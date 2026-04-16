#ifndef EXTI_H
#define EXTI_H

#include "types.h"

/**
 * @file exti.h
 * @brief External Interrupt (EXTI) driver interface for ATmega328P.
 *
 * This module provides an abstraction for configuring and controlling
 * external interrupts INT0 and INT1.
 *
 * It allows:
 * - Selecting interrupt trigger conditions (level/edge)
 * - Enabling and disabling interrupt sources
 * - Clearing pending interrupt flags
 *
 * Note:
 * - INT0 is mapped to PD2
 * - INT1 is mapped to PD3
 * - This module does NOT enable global interrupts (sei())
 *   → must be handled in application code
 */

/**
 * @enum exti_sense_t
 * @brief External interrupt sensing mode for INT0 and INT1.
 *
 * These values map directly to the ISC bit combinations in the EICRA register.
 *
 * - EXTI_LOW_LEVEL    -> interrupt on low level
 * - EXTI_ANY_CHANGE   -> interrupt on any logical change
 * - EXTI_FALLING_EDGE -> interrupt on falling edge
 * - EXTI_RISING_EDGE  -> interrupt on rising edge
 */
typedef enum {
    EXTI_LOW_LEVEL = 0,
    EXTI_ANY_CHANGE,
    EXTI_FALLING_EDGE,
    EXTI_RISING_EDGE
} exti_sense_t;

/**
 * @brief Initialize external interrupt INT0.
 *
 * Configures the interrupt sensing mode for INT0.
 * INT0 is connected to pin PD2 on ATmega328P.
 *
 * @param sense_mode Interrupt trigger mode to be used for INT0.
 */
void exti_int0_init(exti_sense_t sense_mode);

/**
 * @brief Initialize external interrupt INT1.
 *
 * Configures the interrupt sensing mode for INT1.
 * INT1 is connected to pin PD3 on ATmega328P.
 *
 * @param sense_mode Interrupt trigger mode to be used for INT1.
 */
void exti_int1_init(exti_sense_t sense_mode);

/**
 * @brief Enable external interrupt INT0.
 *
 * Enables INT0 in the external interrupt mask register.
 * Any pending INT0 flag may be cleared in the implementation before enabling.
 */
void exti_int0_enable(void);

/**
 * @brief Enable external interrupt INT1.
 *
 * Enables INT1 in the external interrupt mask register.
 * Any pending INT1 flag may be cleared in the implementation before enabling.
 */
void exti_int1_enable(void);

/**
 * @brief Disable external interrupt INT0.
 *
 * Disables INT0 in the external interrupt mask register.
 */
void exti_int0_disable(void);

/**
 * @brief Disable external interrupt INT1.
 *
 * Disables INT1 in the external interrupt mask register.
 */
void exti_int1_disable(void);

/**
 * @brief Clear the pending flag of INT0.
 *
 * Clears the INTF0 flag in EIFR by writing logic 1 to it.
 */
void exti_int0_clear_flag(void);

/**
 * @brief Clear the pending flag of INT1.
 *
 * Clears the INTF1 flag in EIFR by writing logic 1 to it.
 */
void exti_int1_clear_flag(void);

//void exti_int0_set_callback(void (*callback)(void));
//void exti_int1_set_callback(void (*callback)(void));

#endif