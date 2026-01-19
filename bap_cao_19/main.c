#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "gpio.h"

int main(){
	GPIO_configure_led_don(GPIOC,13);
	Configure_Button(GPIOA,0);// cau hinh button PA0 theo kieu PULLDOWN
  while(1){
		
		 Turn_on_turm_off_led(GPIOA,0,GPIOC,13);
	}
//	GPIO_configure_8led(GPIOA,0);
//	  while(1){
//		  Blink_8_led(GPIOA);
//		}
} 