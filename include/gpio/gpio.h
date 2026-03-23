#ifndef GPIO_H
#define GPIO_H

/**
 * @file gpio.h
 * @brief GPIO driver interface for AVR microcontrollers.
 *
 * Provides low-level, register-based GPIO control functions.
 * Designed for minimal overhead and full hardware transparency.
 */


#include <stdint.h>


/* ==================== MACROS ==================== */

/**
 * @brief GPIO direction modes
 */
#define GPIO_INPUT   0
#define GPIO_OUTPUT  1

/**
 * @brief GPIO logic levels
 */
#define GPIO_LOW     0
#define GPIO_HIGH    1


/* ==================== API ==================== */

/**
 * @brief Configure pin direction.
 *
 * @param ddr Pointer to DDR register (e.g., &DDRB)
 * @param pin Pin number (0–7)
 * @param mode GPIO_INPUT or GPIO_OUTPUT
 */
void gpio_pinMode(volatile uint8_t *ddr, uint8_t pin, uint8_t mode);

/**
 * @brief Write digital value to pin.
 *
 * If pin is configured as output:
 * - HIGH → sets pin high
 * - LOW  → sets pin low
 *
 * If pin is configured as input:
 * - HIGH → enables pull-up resistor
 * - LOW  → disables pull-up resistor
 *
 * @param port Pointer to PORT register (e.g., &PORTB)
 * @param pin Pin number (0–7)
 * @param value GPIO_HIGH or GPIO_LOW
 */
void gpio_write(volatile uint8_t *port, uint8_t pin, uint8_t value);

/**
 * @brief Read digital value from pin.
 *
 * @param pin_reg Pointer to PIN register (e.g., &PINB)
 * @param pin Pin number (0–7)
 * @return Non-zero if pin is HIGH, 0 if LOW
 */
uint8_t gpio_read(volatile uint8_t *pin_reg, uint8_t pin);

/**
 * @brief Toggle pin state.
 *
 * @param port Pointer to PORT register (e.g., &PORTB)
 * @param pin Pin number (0–7)
 */
void gpio_toggle(volatile uint8_t *port, uint8_t pin);


#endif /* GPIO_H */