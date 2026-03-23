#include "gpio.h"
#include "types.h"
#include "bit_utils.h"


void gpio_pinMode(volatile uint8_t *ddr, uint8_t pin, uint8_t mode){
  // validate pin range (AVR ports are 8-bit: 0–7)
  if(pin > 7) return;

  switch(mode){
    case GPIO_INPUT:
      // clear bit → configure as input
      CLEAR_BIT(*ddr, pin);
      break;
    case GPIO_OUTPUT:
      // set bit → configure as output
      SET_BIT(*ddr, pin);
      break;
    
    default:
      // fallback to safe state (input)
      CLEAR_BIT(*ddr, pin);
      break;
    }   
}

void gpio_write(volatile uint8_t *port, uint8_t pin, uint8_t value){
  // validate pin range
  if(pin > 7) return;

  // write value to output or control pull-up (if input)
  BIT_WRITE(*port, pin, value);
}

uint8_t gpio_read(volatile uint8_t *pin_reg, uint8_t pin){
  // validate pin range
  if(pin > 7) return;

  // read current logic level from PIN register
  return READ_BIT(*pin_reg, pin);
}

void gpio_toggle(volatile uint8_t *port, uint8_t pin){
  // validate pin range
  if(pin > 7) return;
  
  // invert current output state
  TOGGLE_BIT(*port, pin);
}