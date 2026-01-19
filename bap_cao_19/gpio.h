
#ifndef GPIO_H
#define GPIO_H
#include "stm32f10x_gpio.h"    
/* LED control */
void GPIO_LED_On(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_LED_Off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_LED_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

/* Delay & configure*/
void GPIO_Blink_Delay(uint32_t time);
void GPIO_configure_led_don(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_configure_8led(GPIO_TypeDef*GPIOx,uint16_t mode);
void Blink_8_led(GPIO_TypeDef*GPIOx);


/*Input BUTTON*/
void Configure_Button(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin);
void Turn_on_turm_off_led (GPIO_TypeDef*GPIOBUTTONx,uint16_t BUTTON_PIN,GPIO_TypeDef*GPIOLEDx,uint16_t LED_Pin);

#endif