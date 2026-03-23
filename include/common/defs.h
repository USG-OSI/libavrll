#ifndef DEFS_H
#define DEFS_H

/**
 * @file defs.h
 * @brief Common utility macros and definitions for libavrll.
 *
 * This file provides frequently used macros and compiler attributes
 * to simplify low-level embedded development. It is intended to be
 * lightweight and reusable across all modules.
 */

#include "types.h"
#include <stdbool.h>

/**
 * @brief Attribute to pack structures (no padding between fields).
 *
 * Useful when working with:
 * - Hardware registers
 * - Communication protocols
 * - Memory-mapped data structures
 *
 * Ensures exact memory layout.
 */
#define PACKED __attribute__((packed))

/**
 * @brief Returns the minimum of two values.
 *
 * @param a First value
 * @param b Second value
 * @return The smaller of a and b
 */
#define MIN(a, b)  (((a) < (b)) ? (a) : (b))

/**
 * @brief Returns the maximum of two values.
 *
 * @param a First value
 * @param b Second value
 * @return The larger of a and b
 */
#define MAX(a, b)  (((a) > (b)) ? (a) : (b))

/**
 * @brief Returns the absolute value.
 *
 * @param x Input value
 * @return Absolute value of x
 *
 * @note Be cautious with unsigned types.
 */
#define ABS(x)     (((x) > 0) ? (x) : (-(x)))

#endif /* DEFS_H */