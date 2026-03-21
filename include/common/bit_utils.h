
/**
 * @file bit_utils.h
 * @brief Basic bit manipulation macros for register-level operations.
 *
 * Provides common utilities for setting, clearing, toggling, and reading
 * individual bits in hardware registers.
 */

#ifndef BIT_UTILS_H
#define BIT_UTILS_H

/**
 * @brief Set a specific bit in a register.
 *
 * Sets the bit at the given position to 1.
 *
 * @param reg Target register.
 * @param bit_position Bit index to set.
 */
#define SET_BIT(reg, bit_position) ((reg) |= (1 << (bit_position)))

/**
 * @brief Clear a specific bit in a register.
 *
 * Clears the bit at the given position to 0.
 *
 * @param reg Target register.
 * @param bit_position Bit index to clear.
 */
#define CLEAR_BIT(reg, bit_position) ((reg) &= ~(1 << (bit_position)))

/**
 * @brief Toggle a specific bit in a register.
 *
 * Flips the bit at the given position (0 → 1, 1 → 0).
 *
 * @param reg Target register.
 * @param bit_position Bit index to toggle.
 */
#define TOGGLE_BIT(reg, bit_position) ((reg) ^= (1 << (bit_position)))

/**
 * @brief Read a specific bit from a register.
 *
 * Returns a non-zero value if the bit is set, otherwise returns 0.
 * Can be used directly in conditional statements.
 *
 * @param reg Target register.
 * @param bit_position Bit index to read.
 * @return Non-zero if bit is set, 0 if bit is clear.
 */
#define READ_BIT(reg, bit_position) ((reg) & (1 << (bit_position)))


#endif // BIT_UTILS_H