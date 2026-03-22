#ifndef TYPES_H
#define TYPES_H

/**
 * @file types.h
 * @brief Fixed-width integer type aliases for consistent usage across the library.
 *
 * Defines short and readable aliases for standard fixed-width integer types
 * (from <stdint.h>) to improve code clarity and portability in embedded systems.
 *
 * Aliases:
 *   Unsigned: u8, u16, u32
 *   Signed:   s8, s16, s32
 *
 * This header is minimal and intended for use across all drivers.
 */


#include <stdint.h>

/* Unsigned integer types */
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;


/* Signed integer types */
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

#endif /* TYPES_H */


