#include "exti.h"
#include "gpio.h"
#include "types.h"
#include "bit_utils.h"

/*
 * EXTI driver implementation for ATmega328P
 *
 * This file controls the two dedicated external interrupts:
 *   - INT0 -> PD2
 *   - INT1 -> PD3
 *
 * Main responsibilities of this module:
 *   1. Configure interrupt sensing mode through EICRA
 *   2. Enable/disable interrupt source through EIMSK
 *   3. Clear pending interrupt flags through EIFR
 *
 * Important:
 * - This driver does NOT enable global interrupts.
 *   Global interrupt enable must be done separately in application code using sei().
 *
 * - This implementation currently enables internal pull-up resistors on PD2 and PD3.
 *   That is useful for buttons connected to GND, but may not be desired for every use case.
 *   If later you want more flexibility, GPIO electrical configuration should be separated
 *   from EXTI logic.
 */


/*
 * Initialize INT0.
 *
 * What this function does:
 * - validates the requested sensing mode
 * - configures PD2 as input
 * - enables internal pull-up on PD2
 * - writes the selected sensing mode into ISC01:ISC00 bits in EICRA
 *
 * INT0 uses:
 *   ISC01 ISC00
 *   0     0  -> low level
 *   0     1  -> any logical change
 *   1     0  -> falling edge
 *   1     1  -> rising edge
 *
 * Since exti_sense_t values are defined as 0,1,2,3, they map directly
 * to these two configuration bits.
 */

void exti_int0_init(exti_sense_t sense_mode){
  
  if (sense_mode > EXTI_RISING_EDGE) return;
 
  // INT0 is mapped to PD2
  DDRD &= ~(1 << PD2);
  PORTD |= (1 << PD2);   // internal pull-up enabled

  // Configure ISC01:ISC00 bits
  EICRA &= ~((1 << ISC01) | (1 << ISC00));
  EICRA |= (sense_mode << ISC00);
}

void exti_int1_init(exti_sense_t sense_mode){
  
  if (sense_mode > EXTI_RISING_EDGE) return;
 
  // INT1 is mapped to PD3
  DDRD &= ~(1 << PD3);
  PORTD |= (1 << PD3);

  // Configure ISC11:ISC10 bits
  EICRA &= ~((1 << ISC11) | (1 << ISC10));
  EICRA |= (sense_mode << ISC10);
}

void exti_int0_enable(void){
  // Clear pending flag (write 1 to clear)
  EIFR |= (1 << INTF0);
  EIMSK |= (1 << INT0);
}

void exti_int1_enable(void){
  EIFR |= (1 << INTF1);
  EIMSK |= (1 << INT1);
}

void exti_int0_disable(void){
  EIMSK &= ~(1 << INT0);
  EIFR |= (1 << INTF0);  // clear any latched event
}

void exti_int1_disable(void){
  EIMSK &= ~(1 << INT1);
  EIFR |= (1 << INTF1);
}

void exti_int0_clear_flag(void){
  EIFR |= (1 << INTF0);  // write 1 to clear
}

void exti_int1_clear_flag(void){
  EIFR |= (1 << INTF1);
}