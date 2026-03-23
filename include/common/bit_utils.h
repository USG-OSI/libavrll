
/**
 * @file bit_utils.h
 * @brief Basic bit manipulation macros for register-level operations.
 *
 * Provides common utilities for setting, clearing, toggling, reading, and writing
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


/**
 * @brief Write a specific bit in a register.
 *
 * Sets or clears the specified bit depending on the provided value.
 * If the value is non-zero, the bit is set; otherwise, the bit is cleared.
 *
 * @param reg Target register.
 * @param bit_position Bit index to modify.
 * @param value Value to write (non-zero = set, 0 = clear).
 */
#define WRITE_BIT(REG, BIT, VAL)    ((VAL) ? SET_BIT((REG), (BIT)) : CLEAR_BIT((REG), (BIT)))


#endif // BIT_UTILS_H