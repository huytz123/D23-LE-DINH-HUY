# D23_LE-DINH-HUY
## BAO CAO HOM NAY 
```c
#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"               
#include<math.h>
int nto(int n){// ham check nto
	if(n<2) return 0;
	for(int i=2;i<sqrt(n);i++){
	  if(n%i==0) return 0;
	}
	return 1;
}
int chinhphuong(int n){//ham ktra so chinh phuong
  int can=sqrt(n);
	if(can*can==n) return 1;
	return 0;
}

int hoanhao(int n){//ham ktra so hoan hao, so hoan hao la tong cac uoc = chinh no
   int sum=0;
	for(int i=0;i<n;i++){
		if(n%i==0) sum+=i;
}
	if(sum==n) return 1;
  else return 0;
	}

 void GPIOA_configure(){
  RCC->APB2ENR |=0x00000004;
	 GPIOA->CRL |= 0x03333333;
 }
 void GPIOB_configure(){
  RCC->APB2ENR |=0x00000008;
	 GPIOB->CRL |= 0x00000033;
 }
 void delay(int time){
  int i,j;
	 for(i=0;i<time;i++){
	    for(j=0;j<0x2aff;j++){}
	 }
 }
 
 int mang[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
 int main(){
   GPIOA_configure();
	 GPIOB_configure();
	 GPIOB->ODR &=~0x0003;
	 while(1){
	 for(int i=0;i<100;i++){
		 for(int j=0;j<30;j++){
			 if(hoanhao(i)==1){
			 GPIOA->ODR = mang[i/10]; //hien thi so hang chuc vd 98/10=9
			 GPIOB->ODR |=0x0001;
			 delay(1);
			 GPIOB->ODR &=~0x0001;
			 GPIOA->ODR = mang[i%10]; //hien thi so hang don vi vd 98%10=8
			 GPIOB->ODR |=0x0002;
			 delay(1);
			 GPIOB->ODR&=~0x0002;
			 
		 
		
	 }
 }
 	 }
 }
	 }

```
- Code này nó chạy như này bla bla 
### III END
- Báo cáo em đến đây là hết