#ifndef CPU_FREQ_H
#define CPU_FREQ_H

/**
 * @file cpu_freq.h
 * @brief CPU frequency configuration definitions for AVR systems.
 *
 * This file provides predefined CPU frequency values and ensures that
 * F_CPU is defined. F_CPU is required for timing-related operations such
 * as delays, UART baud rate calculations, and timer configurations.
 */

/**
 * @brief CPU frequency: 1 MHz
 */
#define CPU_FREQ_1MHZ    1000000UL

/**
 * @brief CPU frequency: 8 MHz (common internal oscillator)
 */
#define CPU_FREQ_8MHZ    8000000UL

/**
 * @brief CPU frequency: 16 MHz (common external crystal, e.g., ATmega328P)
 */
#define CPU_FREQ_16MHZ   16000000UL

/**
 * @brief CPU frequency: 20 MHz (upper range for many AVR MCUs)
 */
#define CPU_FREQ_20MHZ   20000000UL

/**
 * @brief Define default CPU frequency if not already defined.
 *
 * F_CPU is used across the system for timing calculations.
 * Users can override this definition by defining F_CPU before including this file
 * or by passing -D F_CPU=<value> to the compiler.
 */
#ifndef F_CPU
#define F_CPU CPU_FREQ_16MHZ
#endif

#endif /* CPU_FREQ_H */