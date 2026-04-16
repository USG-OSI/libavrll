#include "exti.h"
#include "gpio.h"
#include "types.h"
#include "bit_utils.h"



void exti_int0_init(exti_sense_t sense_mode){
  
  if (sense_mode > EXTI_RISING_EDGE) return;
 
  DDRD &= ~(1 << PD2);
  PORTD |= (1 << PD2);

  EICRA &= ~((1 << ISC01) | (1 << ISC00));

  EICRA |= (sense_mode << ISC00);



}


void exti_int1_init(exti_sense_t sense_mode){
  
  if(sense_mode > 3) return;
 
  DDRD &= ~(1 << PD3);
  PORTD |= (1 << PD3);

  EICRA &= ~((1 << ISC11) | (1 << ISC10));

  EICRA |= (sense_mode << ISC10);

}


void exti_int0_enable(void){
  EIFR |= (1 << INTF0);
  EIMSK |= (1 << INT0);
}
void exti_int1_enable(void){
  EIFR |= (1 << INTF1);
  EIMSK |= (1 << INT1);
}

void exti_int0_disable(void){
  EIMSK &= ~(1 << INT0);
  EIFR |= (1 << INTF0);
}
void exti_int1_disable(void){
  EIMSK &= ~(1 << INT1);
  EIFR |= (1 << INTF1);
}

void exti_int0_clear_flag(void){
  EIFR |= (1 << INTF0);
}
void exti_int1_clear_flag(void){
  EIFR |= (1 << INTF1);
}