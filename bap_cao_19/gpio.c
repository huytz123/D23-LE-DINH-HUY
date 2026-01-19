#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "gpio.h"

void GPIO_configure_led_don(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
     if(GPIOx==GPIOA){
		    RCC->APB2ENR |= 0x04;
			  
		 }
		 else if(GPIOx==GPIOB){
		    RCC->APB2ENR |= 0x08;
		 }
		 else if(GPIOx==GPIOC){
		    RCC->APB2ENR |= 0x10;
		 }
		 
		 if(GPIO_Pin < 8){
		     GPIOx->CRL |=3<<GPIO_Pin*4;
			 
		 }
		 else{
		    GPIOx->CRH |=3<<(GPIO_Pin-8)*4;
		 }

}

void GPIO_Blink_Delay(uint32_t time){
	  int i,j;
   for( i=0;i<time;i++){
	   for( j=0;j<0x2aff;j++);
	 }
}

void GPIO_LED_On(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	   GPIO_ResetBits(GPIOx,GPIO_Pin);

}

void GPIO_LED_Off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	   GPIO_SetBits(GPIOx,GPIO_Pin);
}

void GPIO_LED_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
      GPIO_ResetBits(GPIOx,GPIO_Pin);
      GPIO_Blink_Delay(1000);
	    GPIO_SetBits(GPIOx,GPIO_Pin);
	    GPIO_Blink_Delay(1000);
}
void GPIO_configure_8led(GPIO_TypeDef*GPIOx,uint16_t mode){
      if(GPIOx==GPIOA){
		    RCC->APB2ENR |= 0x04;
			  
		 }
		 else if(GPIOx==GPIOB){
		    RCC->APB2ENR |= 0x08;
		 }
		 else if(GPIOx==GPIOC){
		    RCC->APB2ENR |= 0x10;
		 }
		 
		  if(mode==0){//gia su mode =0 la cau hinh 8 led thap
		    GPIOx->CRL |=0x33333333;
		 }
			else{
				GPIOx->CRH |=0x33333333;
			}
			
     
}
//sang dan tung led
int mang[9]={0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};
void Blink_8_led(GPIO_TypeDef*GPIOx){
	   int i;
     for( i=0;i<9;i++){
		    GPIOx->ODR = mang[i];
			 GPIO_Blink_Delay(1000);
			 
		 }
}
//setup BUTTON theo kieu PULLDOWN chua nhan = 0 nhan =1
void Configure_Button(GPIO_TypeDef*GPIOx, uint16_t GPIO_Pin){
      if(GPIOx==GPIOA){
		    RCC->APB2ENR |= 0x04;
			  
		 }
		 else if(GPIOx==GPIOB){
		    RCC->APB2ENR |= 0x08;
		 }
		 else if(GPIOx==GPIOC){
		    RCC->APB2ENR |= 0x10;
		 }
    if(GPIO_Pin<8){
		   GPIOx->IDR |= 8<<(GPIO_Pin*4);
		}
		else{
		   GPIOx->IDR |= 8<<(GPIO_Pin-8)*4;
		}
		// vi la pulldown nen setup TT BD =0
		GPIOx->ODR &=~(1<<GPIO_Pin);
}
int prev_state =0;// trang thai trc do
int led_state =0;// trang thai led
void Turn_on_turm_off_led (GPIO_TypeDef*GPIOBUTTONx,uint16_t BUTTON_PIN,GPIO_TypeDef*GPIOLEDx,uint16_t LED_Pin){
       int buttonstate= GPIOBUTTONx->IDR&(1<<BUTTON_PIN);// trang thai nut nhan
        if(prev_state==0&&buttonstate==1){
				    led_state =! led_state;
					  if(led_state==1){
						   GPIOLEDx->ODR &=~(1<<LED_Pin);// turn on led
						}
						else{
						   GPIOLEDx->ODR |= (1<<LED_Pin);// turn off led
						}
						
				}
				prev_state=buttonstate;
}

